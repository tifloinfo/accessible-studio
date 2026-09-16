# Build and maintain Accessible Studio

Run these commands from the source repository. The build targets Windows x64. Use dependencies compatible with the OBS version you intend to support.

## Prerequisites

- Visual Studio 2022 Build Tools with the C++ desktop workload and Windows SDK.
- Qt 6 development files for MSVC x64. The current test build uses Qt 6.8.3.
- Microsoft Edge WebView2 SDK, unpacked from its NuGet package.
- Node.js and the dependencies locked in package-lock.json for HTML generation.
- Inno Setup 6.7 or later for the installer.

The default dependency folders are dependencies/qt6 and dependencies/webview2. Alternatively, pass their locations to MSBuild.

## Build the DLL

```powershell
msbuild AccessibleStudio.sln /p:Configuration=Release /p:Platform=x64 `
  /p:QtRoot=C:\path\to\qt6 /p:WebView2Root=C:\path\to\webview2
```

Output: build/Release/accessible-studio.dll. Building does not install the plugin into OBS.

## Build, check, and package the release installer

Install the pinned documentation dependencies once:

```powershell
npm ci
```

Then run:

```powershell
.\tools\build-release.ps1 `
  -QtRoot 'C:\path\to\qt6' `
  -WebView2Root 'C:\path\to\webview2' `
  -MSBuildPath 'C:\path\to\MSBuild.exe' `
  -InnoCompiler 'C:\path\to\ISCC.exe' `
  -OutputDirectory 'C:\path\to\release-output'
```

The script rebuilds the plugin and regression executable, runs checks, regenerates HTML, stages the DLL and locales, compiles Setup, and writes SHA256SUMS.txt. It does not install or publish. Without OutputDirectory, it uses outputs/release-1.1.4 beside the repository.

Regression tests compile the actual plugin with mocked OBS interfaces and Qt's offscreen platform. They cover initialization, level conversion, shortcut conflicts, safe Fit recovery, focus handling, response completion, and volume direction and speech. They do not reproduce a screen reader or a full live OBS session.

For a release, review version.rc, installer/AccessibleStudio.iss, build-script filenames, and the build-identity check in tools/test-hardening.ps1 together. A validated test build is not automatically a published release.

## Edit documentation

The English manual is PROJECT_README.md. Other manuals are docs/README.<locale>.md. Audio FAQs are docs/Sound-Features-FAQ.<locale>.md. Six languages are maintained: English, German, Spanish, French, Russian, and Ukrainian.

```powershell
npm run docs:html
node tools/test-documentation.mjs
```

This generates twelve HTML documents. Checks cover local links and anchors, document landmarks and language, and the arguments in translated meter messages. Review content against the implementation; automated checks cannot establish translation quality. Fluent-speaker review is useful for future editorial refinement.

Keep the manuals easy to navigate by heading. Use short paragraphs, task steps, and explicit shortcut lists. Preserve the distinction between fader gain and measured level, between input and output warnings, and between Audible Meter and Sound Doctor reports.

## Installer behavior

The installer source is installer/AccessibleStudio.iss. It checks OBS and missing prerequisites before removing a legacy installation. Required Microsoft downloads are checked for a valid Microsoft Authenticode signature before execution. OBS must be closed for installation or removal; it is not forcibly terminated.

Do not restore or package the abandoned CEF restart helper or experimental browser-dock changes. See ABANDONED-EXPERIMENTS.md. Existing WebView2 result windows remain supported.
