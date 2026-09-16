# Accessible Studio 1.1.4

This release improves reliability, retains explicit volume feedback for JAWS and NVDA, and includes rewritten user documentation in six languages. It targets 64-bit Windows 10/11 and OBS Studio 32.x.

## Changes

- The Accessible Volume Console announces the final dB value after Up or Down, including at the limits. Rapid adjustments use the latest pending value, and moving focus away cancels pending speech.
- Console focus is preserved more reliably when sources change. Restarting Audible Meter retains the open console and selected source. Its letter commands respect editable and embedded-browser controls.
- Audio meter callbacks start only after initialization. Sound Doctor corrects RMS measurements for fader gain, avoids adding compressors when a compressor or limiter already exists, and places new processing in the intended order.
- The shortcut editor detects changes to profiles, scenes, commands, and assignments before saving. Output shortcut persistence resolves a live output reference.
- Fit-to-canvas recovery checks that the scene and transforms remain unchanged before restoring them and centering. It no longer invokes general Undo after an online check. The quality check is skipped in Studio Mode, where Preview and Program can differ.
- WebView2 result actions are queued safely outside callbacks. Outdated actions and duplicate Sound Doctor application are guarded.
- Incomplete online responses are rejected. A redundant second Visual Checker action audit has been removed.
- Installation checks prerequisites before removing a legacy installation. Uninstalling requires OBS to close. The abandoned CEF restart experiment is excluded, and obsolete experiment files are removed during upgrade.
- User guides and audio FAQs have been rewritten in English, German, Spanish, French, Russian, and Ukrainian. HTML manuals include linked contents, clearer headings, and improved reading layout. Measurement announcements are available in all six languages.

## Install or upgrade

Close OBS and run **AccessibleStudio-1.1.4-Setup.exe**. Upgrades from Accessible Studio 1.1.x preserve settings and the stored API key. Migration from Accessible OBS Studio 1.0 removes that older plugin's settings, shortcuts, cache, and key after the installer notice; unrelated OBS content is preserved.

The installer includes the updated manuals. Open them from Tools > Accessible Studio > Open User Manual. The separate DLL asset is supplied for manual deployment; the installer is recommended for ordinary upgrades. SHA256SUMS.txt identifies both assets.

## Known limitations

- JAWS may announce the old slider number before the plugin's correct value with “dB.” The volume itself changes correctly. In user testing, Insert+3 followed by the arrow eliminated the stale announcement, isolating it to JAWS keyboard handling. The issue is being referred to Vispero. Explicit final-value feedback remains enabled for JAWS and NVDA.
- Multi-part settings saves are not yet transactional. Online requests have operation timeouts and shutdown cancellation, but no user cancellation control or overall request deadline.
- Independent fluent-speaker review of the rewritten translations remains useful.
- The installer and DLL are unsigned.

## Validation

The reliability changes passed user testing before release preparation. Release packaging rebuilds the DLL and regression executable with MSVC warnings treated as errors, runs 72 executable regression checks and source hardening checks, verifies all 12 HTML documents and 193 local links/anchors, and compiles the multilingual installer. Regression tests use mocked OBS interfaces and Qt's offscreen platform; they do not simulate screen readers.
