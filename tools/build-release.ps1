param(
    [Parameter(Mandatory=$true)][string]$QtRoot,
    [Parameter(Mandatory=$true)][string]$WebView2Root,
    [Parameter(Mandatory=$true)][string]$MSBuildPath,
    [Parameter(Mandatory=$true)][string]$InnoCompiler,
    [string]$OutputDirectory
)
$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
if (-not $OutputDirectory) { $OutputDirectory = Join-Path (Split-Path -Parent $root) 'outputs\release-1.1.4' }
$OutputDirectory = [IO.Path]::GetFullPath($OutputDirectory)
New-Item -ItemType Directory -Path $OutputDirectory -Force | Out-Null
$previousPath = $env:PATH
$previousPlatform = $env:QT_QPA_PLATFORM
Push-Location $root
try {
    foreach ($project in @('AccessibleStudio.sln', 'ReliabilityTests.vcxproj')) {
        & $MSBuildPath $project /t:Rebuild /p:Configuration=Release /p:Platform=x64 "/p:QtRoot=$QtRoot" "/p:WebView2Root=$WebView2Root" /v:minimal /nologo
        if ($LASTEXITCODE -ne 0) { throw "Build failed: $project" }
    }
    $env:PATH = (Join-Path $QtRoot 'bin') + ';' + $previousPath
    $env:QT_QPA_PLATFORM = 'offscreen'
    # Windows PowerShell treats redirected native stderr as an error record.
    # Qt's offscreen warnings are diagnostic; the test exit code decides success.
    $testPreference = $ErrorActionPreference
    try {
        $ErrorActionPreference = 'Continue'
        & '.\build\Release\reliability-tests.exe' 2>&1 | ForEach-Object { Write-Output "$_" }
        $testExitCode = $LASTEXITCODE
    } finally { $ErrorActionPreference = $testPreference }
    if ($testExitCode -ne 0) { throw 'Executable regression tests failed' }
    & (Join-Path $PSScriptRoot 'test-hardening.ps1')
    & node (Join-Path $PSScriptRoot 'generate-readme-html.mjs')
    if ($LASTEXITCODE -ne 0) { throw 'Documentation generation failed; install the pinned package-lock dependencies with npm ci' }
    & node (Join-Path $PSScriptRoot 'test-documentation.mjs')
    if ($LASTEXITCODE -ne 0) { throw 'Documentation checks failed' }
    New-Item -ItemType Directory -Path 'package\bin\64bit','package\data\locale' -Force | Out-Null
    Copy-Item -LiteralPath 'build\Release\accessible-studio.dll' -Destination 'package\bin\64bit\accessible-studio.dll' -Force
    Copy-Item -Path 'data\locale\*.ini' -Destination 'package\data\locale' -Force
    & $InnoCompiler "/O$OutputDirectory" 'installer\AccessibleStudio.iss'
    if ($LASTEXITCODE -ne 0) { throw 'Installer build failed' }
    Copy-Item -LiteralPath 'RELEASE-NOTES.md' -Destination $OutputDirectory -Force
    $installer = Join-Path $OutputDirectory 'AccessibleStudio-1.1.4-Setup.exe'
    $releaseDll = Join-Path $OutputDirectory 'AccessibleStudio-1.1.4.dll'
    Copy-Item -LiteralPath 'build\Release\accessible-studio.dll' -Destination $releaseDll -Force
    $hashes = Get-FileHash -LiteralPath @($installer, $releaseDll) -Algorithm SHA256 -ErrorAction Stop
    $hashes | ForEach-Object { $_.Hash + '  ' + [IO.Path]::GetFileName($_.Path) } | Set-Content -LiteralPath (Join-Path $OutputDirectory 'SHA256SUMS.txt') -Encoding ASCII
    Write-Output "Release installer: $installer"
} finally {
    $env:PATH = $previousPath
    $env:QT_QPA_PLATFORM = $previousPlatform
    Pop-Location
}
