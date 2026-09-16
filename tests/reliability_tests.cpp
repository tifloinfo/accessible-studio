// SPDX-License-Identifier: GPL-2.0-or-later
// Compile the actual plugin code with fake OBS exports. No installed OBS
// configuration, audio device, credential, or network connection is touched.
#include "../plugin.cpp"
#include <QStandardItemModel>
#include <iostream>
#include <stdexcept>

static int checks{};
static void Check(bool result,const char *message){++checks;if(!result)throw std::runtime_error(message);}
static void CloseMessage(){QTimer::singleShot(0,[]{for(QWidget *w:QApplication::topLevelWidgets())if(auto *box=qobject_cast<QMessageBox*>(w))box->accept();});}
static void *fakeSource=reinterpret_cast<void*>(0x1000);
static obs_volmeter *fakeMeter=reinterpret_cast<obs_volmeter*>(0x2000);
static float fakeGain=1.0f;
static void (*registeredMeter)(void*,const float*,const float*,const float*);
static void *registeredContext;
static bool callbackBeforeInitialization{};
static void SetupAudio(){
    registeredMeter=nullptr;registeredContext=nullptr;callbackBeforeInitialization=false;
    api.source_get_ref=[](void *s){return s;};api.source_release=[](void*){};
    api.source_get_volume=[](const void*){return fakeGain;};api.source_id=[](const void*){return "wasapi_input_capture";};
    api.source_settings=[](const void*)->obs_data*{return nullptr;};api.enum_filters=[](void*,void(*)(void*,void*,void*),void*){};
    api.volmeter_create=[](int){return fakeMeter;};api.volmeter_set_peak_type=[](obs_volmeter*,int){};
    api.volmeter_attach=[](obs_volmeter*,void*){if(registeredMeter)callbackBeforeInitialization=true;return true;};
    api.volmeter_channels=[](obs_volmeter*){return 2;};
    api.volmeter_add_callback=[](obs_volmeter*,void(*fn)(void*,const float*,const float*,const float*),void *p){registeredMeter=fn;registeredContext=p;};
    api.volmeter_remove_callback=[](obs_volmeter*,void(*)(void*,const float*,const float*,const float*),void*){registeredMeter=nullptr;};
    api.volmeter_detach=[](obs_volmeter*){};api.volmeter_destroy=[](obs_volmeter*){};
    api.global_config=[]()->config*{return nullptr;};
}

static void TestAudio(){
    for(double gain:{0.01,0.25,0.5,1.0,2.0})for(double input:{-48.0,-30.0,-15.0,-6.0})
        Check(std::abs(Reliability::PreFaderDb(input+20.0*std::log10(gain),gain)-input)<0.00001,"Pre-fader result depends on fader");
    Check(!std::isfinite(Reliability::PreFaderDb(-20,0)),"Zero gain must not invent a signal");
    Check(!std::isfinite(Reliability::PreFaderDb(NAN,1)),"NaN must not enter a histogram");
    SetupAudio();MeterSource meter;meter.name=QStringLiteral("Test microphone");
    Check(Attach(meter,fakeSource),"Audible Meter attach failed");
    Check(!callbackBeforeInitialization&&meter.source==fakeSource&&meter.channels==2&&registeredContext==&meter,"Audible Meter callback published too early");Detach(meter);
    SetupAudio();fakeGain=0.25f;SoundDoctor::Source doctor;
    Check(SoundDoctor::Attach(doctor,fakeSource),"Sound Doctor attach failed");
    Check(!callbackBeforeInitialization&&doctor.source==fakeSource&&doctor.initialVolume==fakeGain&&doctor.channels==2,"Sound Doctor callback published too early");
    SoundDoctor::running=true;float rms[8],peak[8],input[8];
    for(int i=0;i<8;++i){rms[i]=static_cast<float>(-15+20*std::log10(fakeGain));peak[i]=-15;input[i]=-3;}
    SoundDoctor::Meter(&doctor,rms,peak,input);
    Check(doctor.rmsBins[static_cast<size_t>(SoundDoctor::Bin(-15))]==1,"Sound Doctor histogram contains post-fader RMS");
    SoundDoctor::running=false;SoundDoctor::Detach(doctor);fakeGain=1;
}

struct FakeHotkey{hotkey_id id;const char *name;int type;key_combo combo;};
static FakeHotkey liveHotkey{1,"test.command",REG_FRONTEND,{0,10}};
static void TestEditor(){
    api.enum_hotkeys=[](bool(*fn)(void*,hotkey_id,obs_hotkey*),void *p){fn(p,liveHotkey.id,reinterpret_cast<obs_hotkey*>(&liveHotkey));};
    api.hk_name=[](const obs_hotkey *h){return reinterpret_cast<const FakeHotkey*>(h)->name;};
    api.hk_type=[](const obs_hotkey *h){return reinterpret_cast<const FakeHotkey*>(h)->type;};
    api.enum_bindings=[](bool(*fn)(void*,size_t,obs_hotkey_binding*),void *p){fn(p,0,reinterpret_cast<obs_hotkey_binding*>(&liveHotkey));};
    api.binding_id=[](obs_hotkey_binding *b){return reinterpret_cast<FakeHotkey*>(b)->id;};
    api.binding_combo=[](obs_hotkey_binding *b){return reinterpret_cast<FakeHotkey*>(b)->combo;};
    Hotkey saved;saved.id=1;saved.name="test.command";saved.type=REG_FRONTEND;saved.originalBindings={{0,10}};saved.bindings={{0,11}};hotkeys={saved};
    Check(ValidateEditorBindings(),"Valid staged edit rejected");
    liveHotkey.combo.key=12;Check(!ValidateEditorBindings(),"Externally modified shortcut accepted");
    liveHotkey.combo.key=10;liveHotkey.name="replacement.command";Check(!ValidateEditorBindings(),"Replaced command accepted");
    liveHotkey.name="test.command";hotkeys.clear();
}

static QByteArray sceneJson=R"({"scenes_and_groups":[{"scene_uuid":"test","items":[{"id":1,"rot":0}]}]})";
static QByteArray restoredJson;static int restored{},centered{},undoTriggered{};
static void TestFit(){
    api.studio_mode_active=[](){return false;};api.frontend_current_scene=[](){return fakeSource;};api.frontend_preview_scene=api.frontend_current_scene;
    api.scene_from_source=[](const void*){return fakeSource;};api.scene_save_transforms=[](void*,bool)->obs_data*{return reinterpret_cast<obs_data*>(fakeSource);};
    api.data_json=[](obs_data*){return sceneJson.constData();};api.data_release=[](obs_data*){};
    api.scene_load_transforms=[](const char *json){++restored;restoredJson=json;};api.frontend_save=[](){};
    QStandardItemModel model(1,1);pendingFitSource=model.index(0,0);pendingFitGeneration=obsEditingGeneration;
    pendingFitBefore=R"({"original":true})";pendingFitAfter=CurrentTransformSnapshot();
    auto *center=new QAction(obsMainWindow);center->setObjectName(QStringLiteral("actionCenterToScreen"));QObject::connect(center,&QAction::triggered,[]{++centered;});
    auto *undo=new QAction(obsMainWindow);undo->setObjectName(QStringLiteral("actionMainUndo"));QObject::connect(undo,&QAction::triggered,[]{++undoTriggered;});
    ++obsEditingGeneration;CloseMessage();FinishFitQualityValidation(false);
    Check(restored==0&&centered==0&&undoTriggered==0,"Stale fit modified OBS");
    pendingFitSource=model.index(0,0);pendingFitGeneration=obsEditingGeneration;pendingFitBefore=R"({"original":true})";pendingFitAfter="changed";
    CloseMessage();FinishFitQualityValidation(false);Check(restored==0,"Changed transform overwritten");
    pendingFitSource=model.index(0,0);pendingFitBefore=R"({"original":true})";pendingFitAfter=CurrentTransformSnapshot();
    CloseMessage();FinishFitQualityValidation(false);
    Check(restored==1&&restoredJson==R"({"original":true})"&&centered==1&&undoTriggered==0,"Fit fallback used general Undo or wrong snapshot");
}

static void TestResponsesAndFocus(){
    const QByteArray incomplete=R"({"status":"incomplete","output":[{"content":[{"type":"output_text","text":"partial answer"}]}]})";
    Check(!ResponseResult(incomplete,200,CanvasMode::Detailed,false,false).success,"Truncated API answer accepted");
    const QByteArray completed=R"({"status":"completed","id":"test","output":[{"content":[{"type":"output_text","text":"complete answer"}]}]})";
    Check(ResponseResult(completed,200,CanvasMode::Detailed,false,false).success,"Complete API answer rejected");
    QLineEdit line;QPlainTextEdit plain;QSpinBox spin;QComboBox combo;QWidget custom;custom.setAttribute(Qt::WA_InputMethodEnabled);
    Check(EditableFocus(&line)&&EditableFocus(&plain)&&EditableFocus(&spin)&&EditableFocus(&combo)&&EditableFocus(&custom)&&EditableFocus(nullptr),"Editable focus not protected");
    consoleOpen=true;consoleFocusedUuid=QStringLiteral("source-1");audibleMeterActive=true;StopAudibleMeter(false);
    Check(consoleOpen&&consoleFocusedUuid==QStringLiteral("source-1"),"Stopping meter lost open Console state");
    audibleMeterActive=true;selectedUuid=QStringLiteral("source-1");AudibleMeterConsoleFocusSource({});
    Check(consoleFocusedUuid.isEmpty()&&selectedUuid==QStringLiteral("source-1"),"Leaving controls did not silence measurement or lost H/K selection");audibleMeterActive=false;consoleOpen=false;
}

static std::vector<QString> volumeAnnouncements;
static void CaptureVolumeAnnouncement(QAccessibleEvent *event){
    if(event->type()==QAccessible::Announcement)
        volumeAnnouncements.push_back(static_cast<QAccessibleAnnouncementEvent*>(event)->message());
}
static void TestVolumeDirection(){
    SetupAudio();fakeGain=DbToVolume(-20);
    api.enum_sources=[](bool(*fn)(void*,void*),void *p){fn(p,fakeSource);};
    api.source_output_flags=[](const void*)->uint32_t{return 2;};
    api.source_active=[](const void*){return true;};api.source_audio_active=api.source_active;
    api.source_uuid=[](const void*){return "volume-test";};api.source_name=[](const void*){return "Volume test";};
    api.source_monitoring_type=[](const void*){return 0;};api.source_muted=[](const void*){return false;};
    api.source_set_volume=[](void*,float gain){fakeGain=gain;};
    VolumeConsoleDialog dialog(obsMainWindow);
    auto *slider=dialog.findChild<QSlider*>();Check(slider!=nullptr,"Console slider missing");
    auto *iface=QAccessible::queryAccessibleInterface(slider);
    Check(iface&&iface->valueInterface(),"Console accessible value missing");
    dialog.show();dialog.activateWindow();slider->setFocus();QApplication::processEvents();
    QAccessible::setActive(true);
    auto previousHandler=QAccessible::installUpdateHandler(CaptureVolumeAnnouncement);
    for(bool processEvents:{false,true}){
        slider->setValue(-20);int expected=-20;
        for(int key:{Qt::Key_Down,Qt::Key_Down,Qt::Key_Down,Qt::Key_Up,Qt::Key_Up,Qt::Key_Down,Qt::Key_Up}){
            expected+=key==Qt::Key_Up?1:-1;
            QKeyEvent press(QEvent::KeyPress,key,Qt::NoModifier);QApplication::sendEvent(slider,&press);
            QKeyEvent release(QEvent::KeyRelease,key,Qt::NoModifier);QApplication::sendEvent(slider,&release);
            if(processEvents)QApplication::processEvents();
            Check(slider->value()==expected&&VolumeToDb(fakeGain)==expected,"Volume went in wrong direction");
            Check(iface->valueInterface()->currentValue().toInt()==expected,"Accessible volume lags behind actual volume");
        }
    }
    volumeAnnouncements.clear();
    QKeyEvent down(QEvent::KeyPress,Qt::Key_Down,Qt::NoModifier);
    QKeyEvent up(QEvent::KeyPress,Qt::Key_Up,Qt::NoModifier);
    QApplication::sendEvent(slider,&down);QApplication::sendEvent(slider,&down);QApplication::sendEvent(slider,&up);
    Check(volumeAnnouncements.empty(),"Volume speech runs before key processing finishes");
    QApplication::processEvents();
    Check(volumeAnnouncements.size()==1&&volumeAnnouncements.back()==DbValueText(VolumeToDb(fakeGain)),"Final volume announcement missing or stale");
    volumeAnnouncements.clear();slider->setValue(0);QApplication::sendEvent(slider,&up);QApplication::processEvents();
    Check(volumeAnnouncements.size()==1&&volumeAnnouncements.back()==DbValueText(0),"Volume limit announcement missing");
    volumeAnnouncements.clear();QApplication::sendEvent(slider,&down);dialog.findChild<QPushButton*>()->setFocus();QApplication::processEvents();
    Check(volumeAnnouncements.empty(),"Volume speech followed focus away from slider");
    QAccessible::installUpdateHandler(previousHandler);
}

int main(int argc,char **argv){
    QApplication app(argc,argv);QMainWindow window;obsMainWindow=&window;pluginEventContext=new QObject;
    try{TestAudio();TestEditor();TestFit();TestResponsesAndFocus();TestVolumeDirection();std::cout<<checks<<" reliability checks passed.\n";}
    catch(const std::exception &error){std::cerr<<"FAILED: "<<error.what()<<"\n";return 1;}
    delete pluginEventContext.data();pluginEventContext=nullptr;obsMainWindow=nullptr;return 0;
}
