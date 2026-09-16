// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

enum class MeterSpeech { Green,Yellow,Red,NoSignal,NoSelection,SelectedSilent,SourceSilent,NoActive,SelectedInsufficient,SourceInsufficient,OverallInsufficient,InputManual,NoOutputWarning,Reduced,NoReduction,ManualStillNeeded,NothingToRestore,RestoreSkipped,Restored,SomeChanged };
static QString MText(MeterSpeech id){
    static const std::array<const char*,6> messages[]={
        {"green","grün","зелёная зона","зелена зона","vert","verde"},
        {"yellow","gelb","жёлтая зона","жовта зона","jaune","amarillo"},
        {"red","rot","красная зона","червона зона","rouge","rojo"},
        {"no signal","kein Signal","нет сигнала","немає сигналу","aucun signal","sin señal"},
        {"No Source Selected","Keine Quelle ausgewählt","Источник не выбран","Джерело не вибрано","Aucune source sélectionnée","Ninguna fuente seleccionada"},
        {"The selected source has no current signal.","Die ausgewählte Quelle liefert derzeit kein Signal.","У выбранного источника сейчас нет сигнала.","Вибране джерело зараз не має сигналу.","La source sélectionnée ne fournit aucun signal actuellement.","La fuente seleccionada no tiene señal en este momento."},
        {"%1, no current signal.","%1, derzeit kein Signal.","%1, сейчас нет сигнала.","%1, зараз немає сигналу.","%1, aucun signal actuellement.","%1, sin señal en este momento."},
        {"No active audio signal.","Kein aktives Audiosignal.","Нет активного звукового сигнала.","Немає активного звукового сигналу.","Aucun signal audio actif.","No hay señal de audio activa."},
        {"Not enough active signal for the selected source.","Nicht genügend Signal für die ausgewählte Quelle.","Недостаточно сигнала для оценки выбранного источника.","Недостатньо сигналу для оцінки вибраного джерела.","Signal insuffisant pour évaluer la source sélectionnée.","Señal insuficiente para evaluar la fuente seleccionada."},
        {"Not enough active signal for %1.","Nicht genügend Signal für %1.","Недостаточно сигнала для оценки %1.","Недостатньо сигналу для оцінки %1.","Signal insuffisant pour évaluer %1.","Señal insuficiente para evaluar %1."},
        {"Not enough active signal to determine the overall loudest source.","Nicht genügend Signal, um die insgesamt lauteste Quelle zu bestimmen.","Недостаточно сигнала, чтобы определить самый громкий источник за сеанс.","Недостатньо сигналу, щоб визначити найгучніше джерело за сеанс.","Signal insuffisant pour déterminer la source la plus forte sur la session.","Señal insuficiente para determinar la fuente más fuerte de la sesión."},
        {"Prefader warning requires manual adjustment.","Bei einer Eingangswarnung muss der Pegel manuell angepasst werden.","Уровень до регулятора нужно уменьшить вручную.","Рівень до регулятора потрібно зменшити вручну.","Un avertissement avant le fader nécessite un réglage manuel.","El aviso anterior al fader requiere un ajuste manual."},
        {"No output warning sources.","Keine Quelle mit Ausgangswarnung.","Нет источников с предупреждением о выходном уровне.","Немає джерел із попередженням про вихідний рівень.","Aucune source avec un avertissement de sortie.","Ninguna fuente con aviso de salida."},
        {"%1, reduced %2 dB, fader %3 dB.","%1, um %2 dB abgesenkt, Regler bei %3 dB.","%1: уменьшено на %2 дБ, регулятор %3 дБ.","%1: зменшено на %2 дБ, регулятор %3 дБ.","%1, baisse de %2 dB, fader à %3 dB.","%1, reducción de %2 dB, fader a %3 dB."},
        {"No output warning sources required adjustment.","Keine Quelle erforderte eine Absenkung.","Ни одному источнику не потребовалось уменьшение громкости.","Жодному джерелу не знадобилося зменшення гучності.","Aucune source ne nécessitait de réduction.","Ninguna fuente necesitaba una reducción."},
        {"Manual adjustment may still be needed.","Eine manuelle Anpassung kann weiterhin nötig sein.","Возможно, потребуется дополнительная ручная настройка.","Можливо, знадобиться додаткове ручне налаштування.","Un réglage manuel peut encore être nécessaire.","Puede que aún sea necesario un ajuste manual."},
        {"No automatic level correction to restore.","Keine automatische Pegelkorrektur zum Zurücknehmen.","Нет автоматической коррекции для отмены.","Немає автоматичного коригування для скасування.","Aucune correction automatique à annuler.","No hay ninguna corrección automática que deshacer."},
        {"Automatic level correction was not restored because the source levels changed.","Die Korrektur wurde nicht zurückgenommen, da sich die Quellpegel geändert haben.","Коррекция не отменена: уровни источников уже изменились.","Коригування не скасовано: рівні джерел уже змінилися.","La correction n’a pas été annulée car les niveaux des sources ont changé.","No se deshizo la corrección porque cambiaron los niveles de las fuentes."},
        {"Restored %1.","%1 wiederhergestellt.","Восстановлены уровни: %1.","Відновлено рівні: %1.","Niveaux rétablis : %1.","Niveles restaurados: %1."},
        {" Some source levels had changed."," Einige Quellpegel wurden inzwischen geändert."," Уровни некоторых источников уже изменились."," Рівні деяких джерел уже змінилися."," Certains niveaux avaient été modifiés entre-temps."," Algunos niveles se habían modificado entretanto."},
    };
    return QString::fromUtf8(messages[static_cast<size_t>(id)][LanguageIndex()]);
}
