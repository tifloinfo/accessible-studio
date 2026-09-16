# Accessible Studio user guide

Accessible Studio adds keyboard navigation, spoken feedback, audio tools, and optional visual analysis to OBS Studio on Windows. It is designed for blind users working with JAWS or NVDA.

For audio measurements, tones, and filter recommendations, see the [Sound Features FAQ](docs/Sound-Features-FAQ.en-US.html).

## Install, update, or remove

You need 64-bit Windows 10 or 11 and 64-bit OBS Studio 32.x. An OpenAI API key is needed only for canvas and compatibility analysis. Audio tools and keyboard features work without one.

1. Install OBS from the [official download page](https://obsproject.com/download).
2. Close OBS and run the installer supplied with your Accessible Studio release or test build.
3. Follow the prompts. Setup downloads missing Microsoft WebView2 and Visual C++ components from Microsoft, so Internet access may be needed.
4. Start OBS and open **Tools > Accessible Studio**.

Setup stops if OBS is missing, damaged, or older than 32.0. With OBS 33 or later, it warns about compatibility and offers the [latest plugin release](https://github.com/tifloinfo/accessible-studio/releases/latest). Installing despite the warning does not establish compatibility. Setup asks you to close OBS; it never terminates OBS automatically.

Files go in `C:\ProgramData\obs-studio\plugins\accessible-studio`. OBS and Qt files are not replaced. No desktop shortcut is created. The final installer page can open the manual in the selected language.

**Upgrading from Accessible OBS Studio 1.0:** Setup removes the old plugin, its plugin-specific settings, shortcuts, cache, and stored API key. Other OBS settings and content remain intact. Ordinary upgrades within Accessible Studio 1.1.x preserve settings and the key.

To uninstall, close OBS and remove Accessible Studio through Windows Installed Apps. Uninstalling preserves settings and the stored API key. To delete the key, use **Manage OpenAI API Keys** before uninstalling.

## Find commands and help

Open **Tools > Accessible Studio**. **Audio Tools** contains Accessible Volume Console, Audible Meter, Sound Doctor, and Advanced Sound Settings. **Video Tools** contains the canvas descriptions, Read Text, People and Backgrounds, Visual Checker, and Manage OpenAI API Keys.

The main menu also has **Keyboard Shortcut Editor** and **Open User Manual**. The manual opens in your browser, in the OBS interface language when available and English otherwise.

## Default shortcuts

Existing conflicts or your own changes may leave a command with another shortcut or none.

### Navigate OBS

- F6 / Shift+F6: next / previous main area.
- Ctrl+0: Video Preview.
- Ctrl+1: Scenes.
- Ctrl+2: Sources.
- Ctrl+3: Audio Mixer.
- Ctrl+4: Scene Transitions.
- Ctrl+5: Controls.
- Ctrl+M: visible Media Controls.
- Alt+1 through Alt+9: scenes 1 through 9 in the displayed list; Alt+0: scene 10.

NVDA receives an extra area-name announcement when it is the only detected screen reader. The native Audio Mixer keeps its OBS labels and keyboard behavior.

### Control outputs and audio

- F5: start or stop streaming.
- F7: start or stop recording, including a paused recording.
- Alt+F7: pause or resume recording, if supported by the OBS output configuration.
- F8: start or stop the Virtual Camera.
- Alt+F2: show output and Studio Mode status; Enter or Escape closes it.
- Ctrl+Grave: Accessible Volume Console. Grave means the physical key immediately below Escape; its printed character varies by keyboard layout.
- Ctrl+I: start or stop Audible Meter.
- Ctrl+Shift+D: start or interrupt Sound Doctor.

Completed output changes are announced, as are stream disconnection and recovery.

### Inspect the picture

These commands need an API key and Internet access. Preview does not need focus.

- F3: short description, up to 80 characters.
- Shift+F3: detailed description.
- Alt+F3: visible text, without translation or commentary.
- Ctrl+F3: visible people and their immediate backgrounds.
- F4: Visual Checker, for layout and image-quality problems.

## Change shortcuts

1. Open **Keyboard Shortcut Editor** from the plugin menu.
2. Search for a command and select it with the arrow keys.
3. Press Enter or choose **Add or Edit**, then press the combination in the shortcut field.
4. Use **Add Another Keyboard Shortcut** for more assignments. Confirm, then choose **OK** in the main editor to save.

If another command uses the combination, the editor identifies it and asks whether to reassign it. Delete or Remove in the main editor clears all assignments for the selected command. Closing with unsaved edits offers Save, Discard, or Cancel. Navigation keys and reserved system combinations are not captured.

Saving may be refused if the profile, scene collection, or relevant assignments changed during editing. Reopen the editor to work with the current state.

By default, the plugin keeps OBS shortcuts active only while OBS is the active application. Select **Allow OBS Studio to manage whether keyboard shortcuts work outside OBS** and save to return control to OBS's Hotkey Focus Behavior setting.

At startup or after profile changes, a conflict dialog may offer to keep existing assignments or replace only conflicting combinations with plugin defaults. Keeping them leaves conflicting defaults unassigned. Remembering a choice applies across profiles for that build. Nonempty custom assignments are preserved during default-shortcut migration.

The assignable command **.Open Accessible Studio menu** has no default shortcut.

## Adjust source volume

Press Ctrl+Grave to open **Accessible Volume Console**. Changes take effect immediately.

- Left / Right: previous / next source.
- Up / Down: raise / lower the focused fader by 1 dB.
- Home: set the focused fader to 0 dB.
- 1 through 9: first nine sources; 0: tenth source.
- Space: toggle monitoring and program output together.
- Ctrl+Space: toggle monitoring only.
- Shift+Space: toggle program output only.
- Escape: close and return to the previous OBS control.

Monitoring is sound you hear locally. Program output goes to the stream or recording. Each source also has separate buttons for these controls.

Initially, the console lists active program sources, excluding Preview-only sources in Studio Mode. Activate **Show All Sources** with Enter to include inactive sources; Space does not activate this button. Left and Right reach every source, including those beyond the ten numbered shortcuts. The list and values refresh twice per second.

A normal source cannot be raised above 0 dB here. If its gain was already positive elsewhere in OBS, that range remains available. OBS 32.2 and later support independent mute and monitoring; older supported versions use the previous monitoring states.

After Up or Down, the plugin announces the resulting dB value, including at the limits. Rapid presses combine pending announcements; moving focus away cancels pending volume speech.

**JAWS speech issue:** JAWS may first say the previous number, followed by the plugin's correct value with “dB.” This can sound like a reversed adjustment, although volume changes correctly. In the reported test, Insert+3 followed by the arrow removed the stale announcement. The issue is being referred to Vispero. Explicit dB feedback remains supported for JAWS and NVDA.

## Monitor levels with Audible Meter

Ctrl+I toggles one windowless mode. It watches active sources whether or not OBS is streaming or recording, starts with automatic warnings enabled, and never opens the console automatically or changes filters.

While it is active:

- I: toggle automatic input and output warnings.
- H: current level and zone of the source last selected in the console.
- J: name and current level of the loudest source.
- K: selected source's typical active level during this session.
- L: source with the highest typical active level during this session.
- Shift+I: during an output warning, request a conservative reduction for responsible sources.
- Ctrl+Shift+I: restore the last reduction, except on sources adjusted afterward.

Letter commands are not intercepted in editable controls. H and K report no selected source if none has been selected.

### Understand the tones

- **Low:** after you agree to adjust an input, it is still too high before the OBS fader. Lower the device, Windows input, or source application's gain.
- **Middle:** the focused console source is in OBS's yellow output zone.
- **High:** the focused console source is in red, or an automatic output warning is active.
- **Silence in the console:** green level, no signal, unavailable source, or focus outside source controls.

Console tones are immediate measurements. Automatic warnings require accumulated exposure above a boundary. Turning warnings off with I leaves console measurement tones available.

### Respond to warnings

For an output warning, adjust the fader or press Shift+I. Correction only lowers volume, respects the configured maximum, and cannot repair earlier distortion.

An input warning opens a silent dialog. Yes starts guidance while you lower the original input gain. No or Escape adds that unchanged source to the pre-fader stop list. Silence does not count as success: no-signal announcements are followed by a question about continuing. A sustained healthy signal ends guidance; acknowledge the success message to resume other warnings.

While the console is open, output-warning timing pauses and input problems queue. Closing it presents any still-relevant input problem. Opening it during input guidance asks whether you want to continue adjusting; No saves the opt-out and opens the console.

Under **Advanced Sound Settings > Audible Meter**, adjust warning exposure, safety margin, maximum reduction, and the stop list. These settings do not change console zones or H/J/K/L measurements. There are no separate meter modes, history windows, or report files.

## Review sound with Sound Doctor

Sound Doctor and Audible Meter cannot run together. Sound Doctor uses numerical levels, not speech recognition or AI.

1. Press Ctrl+Shift+D and choose **Start**.
2. Use representative speech and sound for at least two minutes. A source needs 45 seconds of active signal for processing recommendations.
3. Stop streaming and recording before reviewing results. Measurement can continue beyond two minutes while either output is active.
4. Read the recommendations. All checkboxes start unchecked; select only changes you want.
5. Choose **Finish** to apply selected changes, or Escape to close without applying them.

Compression may help a likely live input with large level variation. A limiter protects against future peaks. Sound Doctor cannot reliably distinguish speech from music; leave music compression unselected unless you want that effect.

The report also describes existing filters, possible clipping, changed sources, and insufficient evidence. Sources and filters are checked again before application. Existing processing is not duplicated. A new compressor follows existing processing and precedes a newly added final limiter. Added filters have Sound Doctor names and support OBS Undo and Redo.

Press Ctrl+Shift+D again to interrupt and discard a session after confirmation. No or Escape continues. The confirmation can be disabled with its remember-choice option. If results are already open, the command returns to them. Results hide while streaming or recording is active.

Use **Advanced Sound Settings > Sound Doctor** to change recommendation settings. Apply saves without closing; OK saves and closes; Cancel discards edits since the last Apply. The [audio FAQ](docs/Sound-Features-FAQ.en-US.html) explains the thresholds.

## Seek within media

Select a playable media source, then press Ctrl+M when its Media Controls are visible. Within those controls:

- Left / Right: back / forward 5 seconds.
- Shift+Left / Shift+Right: back / forward 1 minute.
- Page Up / Page Down: back / forward 5 minutes.

Other controls keep their normal key behavior.

## Describe and check the picture

Save a key through **Video Tools > Manage OpenAI API Keys**. After validation, Windows Credential Manager stores it for your Windows account. A stored key is never displayed. Failed replacement leaves the existing key intact; removal requires confirmation.

A canvas shortcut captures the rendered OBS image. A click confirms the request. Results open in an accessible WebView2 window; closing it restores focus when appropriate. New answers are announced once. **Copy Latest Result** copies only the latest answer.

Ask image-related follow-up questions or choose available preset descriptions. These reuse the image conversation. Closing the window or starting a new capture ends that conversation. **Check Again** submits a fresh frame to compare changes.

Visual Checker rates visible problems by their effect on viewers. It checks lighting, framing, cropping, scale, blur, grain, blank captures, obstructions, and distracting backgrounds. It does not judge wording, facts, opinions, spelling, or caption meaning. Text matters only when its visual presentation is a problem. Ordinary Zoom controls or borders alone do not establish that a meeting is windowed.

### Apply a suggested fix

**Suggested Fixes** or **Fix Automatically** opens a video-source chooser, then applicable fixes and risks. With one source, the chooser is skipped. You approve one fix at a time.

Only supported whole-source transforms are available. Stretch to Screen is never offered. This feature cannot control outputs, audio, credentials, scene deletion, or arbitrary commands.

After Fit to Canvas, a further image check can assess enlargement quality. If quality is unacceptable or cannot be confirmed, recovery restores captured transforms and centers the source only when the scene and transforms still match the expected state. It does not invoke general Undo after the network wait or overwrite intervening edits. The online quality check is skipped in Studio Mode because Preview and Program can differ.

## Compatibility, privacy, and cost

For an OBS major version beyond the tested range, the plugin offers Cancel, Run Anyway, or Analyze Compatibility. Analysis combines local read-only checks with official OBS information through OpenAI. It estimates risk, not guaranteed compatibility. A successful report is cached for the exact OBS version, plugin version, and architecture, and copied to the Clipboard.

Canvas analysis sends the captured image, OBS language, instructions, and follow-up questions to OpenAI. Check Again sends a new image. Compatibility analysis sends version and dependency information and a description of plugin capabilities. The key authenticates requests; it is not analysis content. API charges are the key owner's responsibility.

Audio tools work locally with fixed-size level statistics in memory. They do not record or transmit audio or save measurement histories. Preferences and input-warning opt-outs are retained. The plugin includes no advertising or telemetry.

## Troubleshooting

- **Plugin missing:** check OBS is 64-bit and was closed during installation.
- **Shortcut unavailable:** check the shortcut editor, OBS Hotkeys, conflicts, and Hotkey Focus Behavior.
- **No API key:** open Manage OpenAI API Keys; other features remain available.
- **No Media Controls:** select a playable source and make its controls visible.
- **Results window unavailable:** repair WebView2 or rerun Setup with Internet access.
- **Two volume numbers in JAWS:** use the value followed by “dB”; see Adjust source volume.

## Project and license

Accessible Studio is an independent third-party plugin, not developed, sponsored, or endorsed by the OBS Project or its contributors. OBS and OBS Studio are registered trademarks of Wizards of OBS LLC.

Copyright © 2026 [Tiflo.Info](https://tiflo.info). GNU GPL version 2 or later; see [LICENSE.txt](LICENSE.txt) and [LICENSE-GPL-2.0.txt](LICENSE-GPL-2.0.txt). Names and logos remain separately protected branding.

Other languages: [Deutsch](docs/README.de-DE.md), [Español](docs/README.es-ES.md), [Français](docs/README.fr-FR.md), [Русский](docs/README.ru-RU.md), [Українська](docs/README.uk-UA.md).
