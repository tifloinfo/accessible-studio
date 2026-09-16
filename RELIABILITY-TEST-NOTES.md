# Accessible Studio 1.1.4 Volume Speech Test 2

Private Windows x64 test build, 16 September 2026. Targets OBS Studio 32.x. This is not a public release. The DLL version is 1.1.4.2 and carries the Windows prerelease flag.

## Accepted volume speech improvement

This build retains the Reliability Test 1 fixes and adds an explicit, brief dB announcement after Up or Down finishes processing in the Volume Console. Pending announcements are coalesced and canceled when focus leaves the slider. The volume calculation is unchanged.

Live feedback isolated the stale first announcement to JAWS keyboard handling: Insert+3 followed by an arrow produces only the correct dB announcement. Ordinary arrow presses can still produce the old bare-number announcement followed by the correct dB announcement. The user is forwarding the JAWS issue to Vispero and approved retaining the explicit dB feedback in mainline for both JAWS and NVDA. This is now supported behavior, not a temporary diagnostic change. Volume adjustment itself follows the requested direction.

Close OBS before installing. Starting at 0 dB (Home), press Down three times, then Up twice, then Down twice. Expected final values after each arrow: -1, -2, -3, -2, -1, -2, -3 dB. Repeat slowly and rapidly. Also test the 0 dB limit, changing sources, and closing the Console. If possible compare the actual OBS mixer value with JAWS speech. Roll back by reinstalling the retained Reliability Test 1 installer with OBS closed.

All 72 executable checks pass, including actual Console key events in both directions, mocked OBS gain, accessible numeric values, final speech coalescing, range-limit speech, and cancellation after focus changes. These checks do not simulate JAWS.

## Changes

- Removed the abandoned CEF accessibility experiment and restart helper. Setup removes the obsolete helper if a previous experiment installed it. The separate WebView2 reports remain supported.
- The shortcut editor rejects saves after a profile, scene, command, or shortcut assignment changes. Output hotkeys resolve a live output reference when saving.
- Fit-to-canvas recovery verifies the scene and its transforms before restoring the captured state. It no longer invokes general Undo after waiting for an online answer. In Studio Mode, it skips the online check because the edited Preview and captured Program can differ.
- WebView2 actions that can open dialogs are queued outside the browser callback. Stale or duplicate report actions are ignored.
- Audio meters publish their callbacks after initialization. Sound Doctor converts RMS measurements to the level before the source fader. New compressors follow existing processing; an existing compressor or limiter suppresses compressor recommendations. Selected new compressors are applied before new limiters.
- Audible Meter protects editable and embedded-browser controls from its letter commands. Console focus and the selected source survive meter stop/start; leaving source controls silences their tone. Source refresh preserves the focused control where possible.
- Meter measurements and correction announcements now have text in all six supported languages.
- Online responses marked incomplete are rejected. Removed the second AI review that matched issues by list position.
- Prerequisites are checked before removing a legacy installation. Uninstall now waits for OBS to close. Corrected documentation links and several inaccurate passages.

## User acceptance

The user reports successful testing of all recent reliability changes and authorizes committing them. The explicit volume announcement is accepted for both JAWS and NVDA. The separate stale JAWS arrow-key announcement is being referred to Vispero.

## Automated validation

The build script rebuilds the DLL and executable regression tests with MSVC warnings treated as errors, runs the tests and source hardening checks, regenerates all twelve HTML documents, checks local links and translated message arguments, and compiles the installer. SHA256SUMS.txt identifies the resulting installer and DLL.

The executable tests exercise meter initialization and level conversion, stale shortcut assignments, safe Fit recovery, incomplete online responses, editable controls, and console state. They use mocked OBS interfaces and Qt's offscreen platform. They do not validate live OBS behavior, JAWS speech, WebView2 navigation, or installation on another machine.

## Suggested manual checks

1. Close OBS and install this build. Confirm OBS loads the plugin. For rollback, close OBS and reinstall the retained 1.1.3 installer. As with ordinary upgrades from 1.1.x, settings and the API key are preserved; migration from the old 1.0.x product still uses its existing destructive migration notice.
2. Open the Console, select a source, toggle Ctrl+I off and on, and try I, H, J, K, and L. Move to non-source controls and check that tones stop. Add or remove a source and check focus. Type those letters in editable controls and browser forms.
3. Open the shortcut editor. Test a normal save. Change the profile or an assignment through another means while it is open, then confirm a stale save is refused.
4. Test Fit-to-canvas in a disposable scene, including changing the source transform while an online check is pending. Confirm no unrelated edit is undone. In Studio Mode, confirm the Preview explanation appears.
5. Run Sound Doctor with representative microphone audio at different fader levels. Check compressor thresholds, insertion order, and Undo/Redo. Open report dialogs repeatedly and confirm keyboard focus and JAWS output remain usable.
6. Check the new meter announcements in the languages you use. Close OBS before testing uninstall; canceling the running-OBS prompt should preserve the installation.

## Remaining work before a release

- Multi-part settings and shortcut-policy saves can still partially succeed if a later write fails. A coordinated save and rollback design needs dedicated failure-injection tests.
- Online requests still need user cancellation and an overall request deadline. Existing timeout and shutdown handling remains in place.
- English documentation needs an editorial rewrite, and the other languages need full rewrites and fluent-speaker review. This build contains targeted factual corrections, not that rewrite.
- Broader separation of the large C++ implementation, official OBS header integration, and additional integration tests remain follow-up work.
- The user has accepted the recent reliability changes after successful testing. Independent multilingual editorial review remains desirable. The installer is unsigned.

## Rebuilding

Install the pinned Node dependencies with `npm ci`. Run `tools/build-test.ps1` with `-QtRoot`, `-WebView2Root`, `-MSBuildPath`, and `-InnoCompiler` pointing to the local Qt 6.8.3 MSVC x64 kit, WebView2 SDK, Visual Studio 2022 MSBuild, and Inno Setup 6 compiler. An optional `-OutputDirectory` selects the artifact folder. The script builds and packages; it does not install or publish.
