# This file is part of the Phalcon.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information, please view the LICENSE.txt
# file that was distributed with this source code.

Function PrepareReleaseNote {
	$ReleaseFile = "${Env:APPVEYOR_BUILD_FOLDER}\package\RELEASE.txt"
	$ReleaseDate = Get-Date -Format g

	Write-Output "Release date: ${ReleaseDate}"                           | Out-File -Encoding "ASCII" -Append "${ReleaseFile}"
	Write-Output "Release version: ${Env:APPVEYOR_BUILD_VERSION}"         | Out-File -Encoding "ASCII" -Append "${ReleaseFile}"
	Write-Output "Git commit: ${Env:APPVEYOR_REPO_COMMIT}"                | Out-File -Encoding "ASCII" -Append "${ReleaseFile}"
	Write-Output "Build type: ${Env:BUILD_TYPE}"                          | Out-File -Encoding "ASCII" -Append "${ReleaseFile}"
	Write-Output "Platform: ${Env:PLATFORM}"                              | Out-File -Encoding "ASCII" -Append "${ReleaseFile}"
	Write-Output "Target PHP version: ${Env:PHP_MINOR}"                   | Out-File -Encoding "ASCII" -Append "${ReleaseFile}"
	Write-Output "Build worker image: ${Env:APPVEYOR_BUILD_WORKER_IMAGE}" | Out-File -Encoding "ASCII" -Append "${ReleaseFile}"
}

Function PrepareReleasePackage {
	PrepareReleaseNote

	$CurrentPath = (Get-Item -Path ".\" -Verbose).FullName
	$PackagePath = "${Env:APPVEYOR_BUILD_FOLDER}\package"

	FormatReleaseFiles

	Copy-Item -Path (Join-Path -Path $Env:APPVEYOR_BUILD_FOLDER -ChildPath '\*') -Filter '*.txt' -Destination "${PackagePath}" -Force
	Copy-Item "${Env:RELEASE_DLL_PATH}" "${PackagePath}"

	Set-Location "${PackagePath}"
	$result = (& 7z a "${Env:RELEASE_ZIPBALL}.zip" "*.*")

	$7zipExitCode = $LASTEXITCODE
	If ($7zipExitCode -ne 0) {
		Set-Location "${CurrentPath}"
		Throw "An error occurred while creating release zippbal to [${Env:RELEASE_ZIPBALL}.zip]. 7Zip Exit Code was [${7zipExitCode}]"
	}

	Move-Item "${Env:RELEASE_ZIPBALL}.zip" -Destination "${Env:APPVEYOR_BUILD_FOLDER}"

	Set-Location "${CurrentPath}"
}

Function FormatReleaseFiles {
	EnsurePandocIsInstalled

	$CurrentPath = (Get-Item -Path ".\" -Verbose).FullName

	Set-Location "${Env:APPVEYOR_BUILD_FOLDER}"

	Get-ChildItem (Get-Item -Path ".\" -Verbose).FullName *.md |
	ForEach-Object {
		$BaseName = $_.BaseName
		pandoc -f markdown -t html5 "${BaseName}.md" > "package/${BaseName}.html"
	}

	If (Test-Path -Path "package/CHANGELOG.html") {
		(Get-Content "package/CHANGELOG.html") | ForEach-Object {
            $_ -replace ".md", ".html"
        } | Set-Content "package/CHANGELOG.html"
	}

	Set-Location "${CurrentPath}"
}

Function InstallBuildDependencies {
	EnsureChocolateyIsInstalled
	EnsureComposerIsInstalled

	$InstallProcess = Start-Process "choco" `
        -WindowStyle Hidden `
        -ArgumentList 'install', '-y --cache-location=C:\Downloads\Choco pandoc' `
        -WorkingDirectory "${Env:APPVEYOR_BUILD_FOLDER}"

	If (-not (Test-Path "${Env:APPVEYOR_BUILD_FOLDER}\package")) {
		New-Item -ItemType Directory -Force -Path "${Env:APPVEYOR_BUILD_FOLDER}\package" | Out-Null
	}

	If (-not (Test-Path "${Env:APPVEYOR_BUILD_FOLDER}\vendor")) {
		$Php = "${Env:PHP_PATH}\php.exe"
		$ComposerOptions = "-q -n --no-progress -o --prefer-dist --no-suggest --ignore-platform-reqs"

		Set-Location "${Env:APPVEYOR_BUILD_FOLDER}"
		& cmd /c ".\composer.bat install ${ComposerOptions}"
		& cmd /c ".\composer.bat require ${ComposerOptions} `"phalcon/zephir:${Env:ZEPHIR_VERSION}`""
	}
}

Function EnsurePandocIsInstalled {
	If (-not (Get-Command "pandoc" -ErrorAction SilentlyContinue)) {
		$PandocInstallationDirectory = "${Env:ProgramData}\chocolatey\bin"

		If (-not (Test-Path "$PandocInstallationDirectory")) {
			Throw "The pandoc is needed to use this module"
		}

		$Env:Path += ";$PandocInstallationDirectory"
	}

	& "pandoc" -v
}

Function EnableExtension {
	If (-not (Test-Path "${Env:RELEASE_DLL_PATH}")) {
		Throw "Unable to locate extension path: ${Env:RELEASE_DLL_PATH}"
	}

	Copy-Item "${Env:RELEASE_DLL_PATH}" "${Env:PHP_PATH}\ext\${Env:EXTENSION_FILE}"

	$IniFile = "${Env:PHP_PATH}\php.ini"
	$PhpExe  = "${Env:PHP_PATH}\php.exe"

	If (-not [System.IO.File]::Exists($IniFile)) {
		Throw "Unable to locate ${IniFile}"
	}

	If (Test-Path -Path "${PhpExe}") {
		& "${PhpExe}" --ri "${Env:EXTENSION_NAME}"

		$PhpExitCode = $LASTEXITCODE
		If ($PhpExitCode -ne 0) {
			PrintPhpInfo
			Throw "An error occurred while enabling [${Env:EXTENSION_NAME}] in [$IniFile]. PHP Exit Code was [$PhpExitCode]."
		}
	}
}

Function InitializeReleaseVars {
	If ($Env:BUILD_TYPE -Match "nts-Win32") {
		$Env:RELEASE_ZIPBALL = "${Env:PACKAGE_PREFIX}_${Env:PLATFORM}_vc${Env:VC_VERSION}_php${Env:PHP_MINOR}_${Env:APPVEYOR_BUILD_VERSION}_nts"

		If ($Env:PLATFORM -eq 'x86') {
			$Env:RELEASE_FOLDER = "Release"
		} Else {
			$Env:RELEASE_FOLDER = "x64\Release"
		}
	} Else {
		$Env:RELEASE_ZIPBALL = "${Env:PACKAGE_PREFIX}_${Env:PLATFORM}_vc${Env:VC_VERSION}_php${Env:PHP_MINOR}_${Env:APPVEYOR_BUILD_VERSION}"

		If ($Env:PLATFORM -eq 'x86') {
			$Env:RELEASE_FOLDER = "Release_TS"
		} Else {
			$Env:RELEASE_FOLDER = "x64\Release_TS"
		}
	}

	$Env:RELEASE_DLL_PATH = "${Env:APPVEYOR_BUILD_FOLDER}\build\php7\safe\${Env:RELEASE_FOLDER}\${Env:EXTENSION_FILE}"
}

Function PrintLogs {
	Param([Parameter(Mandatory=$true)][System.String] $BasePath)

	If (Test-Path -Path "${Env:BasePath}\compile-errors.log") {
		Get-Content -Path "${Env:BasePath}\compile-errors.log"
	}

	If (Test-Path -Path "${Env:BasePath}\compile.log") {
		Get-Content -Path "${Env:BasePath}\compile.log"
	}

	If (Test-Path -Path "${Env:BasePath}\configure.js") {
		Get-Content -Path "${Env:BasePath}\configure.js"
	}
}

Function PrintVars {
	Write-Host ($Env:Path).Replace(';', "`n")

	Get-ChildItem Env:
}

Function PrintDirectoriesContent {
	Get-ChildItem -Path "${Env:APPVEYOR_BUILD_FOLDER}"

	If (Test-Path -Path "C:\Downloads") {
		Get-ChildItem -Path "C:\Downloads"
	}

	If (Test-Path -Path "C:\Projects") {
		Get-ChildItem -Path "C:\Projects"
	}

	If (Test-Path -Path "${Env:PHP_PATH}\ext") {
		Get-ChildItem -Path "${Env:PHP_PATH}\ext"
	}

	$ReleasePath = Split-Path -Path "${Env:RELEASE_DLL_PATH}"
	If (Test-Path -Path "${ReleasePath}") {
		Get-ChildItem -Path "${ReleasePath}"
	}

	$BuildPath = Split-Path -Path "${ReleasePath}"
	If (Test-Path -Path "${BuildPath}") {
		Get-ChildItem -Path "${BuildPath}"
	}

    If (Test-Path -Path "${Env:PHP_DEVPACK}") {
        Get-ChildItem -Path "${Env:PHP_DEVPACK}"
    }
}

Function PrintPhpInfo {
	$IniFile = "${Env:PHP_PATH}\php.ini"
	$PhpExe = "${Env:PHP_PATH}\php.exe"

	If (Test-Path -Path "${PhpExe}") {
		Write-Host ""
		& "${PhpExe}" -v

		Write-Host ""
		& "${PhpExe}" -m

		Write-Host ""
		& "${PhpExe}" -i
	} ElseIf (Test-Path -Path "${IniFile}") {
		Get-Content -Path "${IniFile}"
	}
}

Function InitializeBuildVars {
	switch ($Env:VC_VERSION) {
		'14' {
			If (-not (Test-Path $Env:VS120COMNTOOLS)) {
				Throw'The VS120COMNTOOLS environment variable is not set. Check your MS VS installation'
			}
			$Env:VSCOMNTOOLS = $Env:VS120COMNTOOLS -replace '\\$', ''

			break
		}
		'15' {
			If (-not (Test-Path $Env:VS140COMNTOOLS)) {
				Throw'The VS140COMNTOOLS environment variable is not set. Check your MS VS installation'
			}
			$Env:VSCOMNTOOLS = $Env:VS140COMNTOOLS -replace '\\$', ''
			break
		}
		default {
			Throw'This script is designed to run with MS VS 14/15. Check your MS VS installation'
			break
		}
	}

	If ($Env:PLATFORM -eq 'x64') {
		$Env:ARCH = 'x86_amd64'
	} Else {
		$Env:ARCH = 'x86'
	}
}

Function TuneUpPhp {
	$IniFile = "${Env:PHP_PATH}\php.ini"
	$ExtPath = "${Env:PHP_PATH}\ext"

	If (-not [System.IO.File]::Exists($IniFile)) {
		Throw "Unable to locate $IniFile file"
	}

	Write-Output ""                                  | Out-File -Encoding "ASCII" -Append $IniFile
	Write-Output "extension_dir = ${ExtPath}"        | Out-File -Encoding "ASCII" -Append $IniFile
	Write-Output "memory_limit = 256M"               | Out-File -Encoding "ASCII" -Append $IniFile
	Write-Output ""                                  | Out-File -Encoding "ASCII" -Append $IniFile
	Write-Output "extension = php_curl.dll"          | Out-File -Encoding "ASCII" -Append $IniFile
	Write-Output "extension = php_openssl.dll"       | Out-File -Encoding "ASCII" -Append $IniFile
	Write-Output "extension = php_mbstring.dll"      | Out-File -Encoding "ASCII" -Append $IniFile
	Write-Output "extension = php_pdo_sqlite.dll"    | Out-File -Encoding "ASCII" -Append $IniFile
	Write-Output "extension = php_fileinfo.dll"      | Out-File -Encoding "ASCII" -Append $IniFile
	Write-Output "extension = php_gettext.dll"       | Out-File -Encoding "ASCII" -Append $IniFile
	Write-Output "extension = php_gd2.dll"           | Out-File -Encoding "ASCII" -Append $IniFile
	Write-Output "extension = ${Env:EXTENSION_FILE}" | Out-File -Encoding "ASCII" -Append $IniFile
	Write-Output "extension = php_zephir_parser.dll" | Out-File -Encoding "ASCII" -Append $IniFile
}

Function InstallPhpDevPack {
	Write-Host "Install PHP Dev pack: ${Env:PHP_VERSION}" -foregroundcolor Cyan

	$RemoteUrl = "http://windows.php.net/downloads/releases/php-devel-pack-${Env:PHP_VERSION}-${Env:BUILD_TYPE}-vc${Env:VC_VERSION}-${Env:PLATFORM}.zip"
	$DestinationPath = "C:\Downloads\php-devel-pack-${Env:PHP_VERSION}-${Env:BUILD_TYPE}-VC${Env:VC_VERSION}-${Env:PLATFORM}.zip"

	If (-not (Test-Path $Env:PHP_DEVPACK)) {
		If (-not [System.IO.File]::Exists($DestinationPath)) {
			Write-Host "Downloading PHP Dev pack: ${RemoteUrl} ..."
			DownloadFile $RemoteUrl $DestinationPath
		}

		$DestinationUnzipPath = "${Env:Temp}\php-${Env:PHP_VERSION}-devel-VC${Env:VC_VERSION}-${Env:PLATFORM}"

		If (-not (Test-Path "$DestinationUnzipPath")) {
			Expand-Item7zip $DestinationPath $Env:Temp
		}

		Move-Item -Path $DestinationUnzipPath -Destination $Env:PHP_DEVPACK
	}
}

Function InstallStablePhalcon {
	$BaseUri = "https://github.com/phalcon/cphalcon/releases/download"
	$PatchSuffix = ".0"
	$LocalPart = "${Env:PACKAGE_PREFIX}_${Env:PLATFORM}_vc${Env:VC_VERSION}_php${Env:PHP_MINOR}${PatchSuffix}"


	If ($Env:BUILD_TYPE -Match "nts-Win32") {
		$VersionSuffix = "${Env:PHALCON_STABLE_VERSION}_nts"
	} Else {
		$VersionSuffix = "${Env:PHALCON_STABLE_VERSION}"
	}

	$RemoteUrl = "${BaseUri}/v${Env:PHALCON_STABLE_VERSION}/${LocalPart}_${VersionSuffix}.zip"
	$DestinationPath = "C:\Downloads\${LocalPart}_${VersionSuffix}.zip"

	If (-not (Test-Path "${Env:PHP_PATH}\ext\${Env:EXTENSION_FILE}")) {
		If (-not [System.IO.File]::Exists($DestinationPath)) {
			Write-Host "Downloading stable Phalcon: ${RemoteUrl} ..."
			DownloadFile $RemoteUrl $DestinationPath
		}

		Expand-Item7zip $DestinationPath "${Env:PHP_PATH}\ext"
	}
}

Function InstallParser {
	$BaseUri = "https://github.com/phalcon/php-zephir-parser/releases/download"
	$LocalPart = "zephir_parser_${Env:PLATFORM}_vc${Env:VC_VERSION}_php${Env:PHP_MINOR}"

	If ($Env:BUILD_TYPE -Match "nts-Win32") {
		$VersionPrefix = "-nts"
	} Else {
		$VersionPrefix = ""
	}

	$RemoteUrl = "${BaseUri}/v${Env:PARSER_VERSION}/${LocalPart}${VersionPrefix}_${Env:PARSER_VERSION}-${Env:PARSER_RELEASE}.zip"
	$DestinationPath = "C:\Downloads\${LocalPart}${VersionPrefix}_${Env:PARSER_VERSION}-${Env:PARSER_RELEASE}.zip"

	If (-not (Test-Path "${Env:PHP_PATH}\ext\php_zephir_parser.dll")) {
		If (-not [System.IO.File]::Exists($DestinationPath)) {
			Write-Host "Downloading Zephir Parser: ${RemoteUrl} ..."
			DownloadFile $RemoteUrl $DestinationPath
		}

		Expand-Item7zip $DestinationPath "${Env:PHP_PATH}\ext"
	}
}

Function InstallPhp {
	Write-Host "Install PHP: ${Env:PHP_VERSION}" -foregroundcolor Cyan

	$RemoteUrl = "http://windows.php.net/downloads/releases/php-${Env:PHP_VERSION}-${Env:BUILD_TYPE}-vc${Env:VC_VERSION}-${Env:PLATFORM}.zip"
	$DestinationPath = "C:\Downloads\php-${Env:PHP_VERSION}-${Env:BUILD_TYPE}-VC${Env:VC_VERSION}-${Env:PLATFORM}.zip"

	If (-not (Test-Path $Env:PHP_PATH)) {
		If (-not [System.IO.File]::Exists($DestinationPath)) {
			Write-Host "Downloading PHP source code: $RemoteUrl ..."
			DownloadFile $RemoteUrl $DestinationPath
		}

		Expand-Item7zip "$DestinationPath" "${Env:PHP_PATH}"
	}

	If (-not (Test-Path "${Env:PHP_PATH}\php.ini")) {
		Copy-Item "${Env:PHP_PATH}\php.ini-development" "${Env:PHP_PATH}\php.ini"
	}
}

Function InstallSdk {
	Write-Host "Install PHP SDK binary tools: ${Env:PHP_SDK_VERSION}" -foregroundcolor Cyan

	$RemoteUrl = "https://github.com/OSTC/php-sdk-binary-tools/archive/php-sdk-${Env:PHP_SDK_VERSION}.zip"
	$DestinationPath = "C:\Downloads\php-sdk-${Env:PHP_SDK_VERSION}.zip"

	If (-not (Test-Path $Env:PHP_SDK_PATH)) {
		If (-not [System.IO.File]::Exists($DestinationPath)) {
			Write-Host "Downloading PHP SDK binary tools: $RemoteUrl ..."
			DownloadFile $RemoteUrl $DestinationPath
		}

		$DestinationUnzipPath = "${Env:Temp}\php-sdk-binary-tools-php-sdk-${Env:PHP_SDK_VERSION}"

		If (-not (Test-Path "$DestinationUnzipPath")) {
			Expand-Item7zip $DestinationPath $Env:Temp
		}

		Move-Item -Path $DestinationUnzipPath -Destination $Env:PHP_SDK_PATH
	}
}

Function Ensure7ZipIsInstalled {
	If (-not (Get-Command "7z" -ErrorAction SilentlyContinue)) {
		$7zipInstallationDirectory = "${Env:ProgramFiles}\7-Zip"

		If (-not (Test-Path "$7zipInstallationDirectory")) {
			Throw "The 7-zip file archiver is needed to use this module"
		}

		$Env:Path += ";$7zipInstallationDirectory"
	}
}

Function EnsureRequiredDirectoriesPresent {
	If (-not (Test-Path 'C:\Downloads')) {
		New-Item -ItemType Directory -Force -Path 'C:\Downloads' | Out-Null
	}

	If (-not (Test-Path 'C:\Downloads\Choco')) {
		New-Item -ItemType Directory -Force -Path 'C:\Downloads\Choco' | Out-Null
	}

	If (-not (Test-Path 'C:\Projects')) {
		New-Item -ItemType Directory -Force -Path 'C:\Projects' | Out-Null
	}
}

Function EnsureChocolateyIsInstalled {
	If (-not (Get-Command "choco" -ErrorAction SilentlyContinue)) {
		$ChocolateyInstallationDirectory = "${Env:ProgramData}\chocolatey\bin"

		If (-not (Test-Path "$ChocolateyInstallationDirectory")) {
			Throw "The choco is needed to use this module"
		}

		$Env:Path += ";$ChocolateyInstallationDirectory"
	}
}

Function EnsureComposerIsInstalled {
    $ComposerBatch = "${Env:APPVEYOR_BUILD_FOLDER}\composer.bat"

    If (-not (Test-Path -Path $ComposerBatch)) {
        $Php = "${Env:PHP_PATH}\php.exe"
        $ComposerPhar = "${Env:APPVEYOR_BUILD_FOLDER}\composer.phar"

        DownloadFile "https://getcomposer.org/composer.phar" "${ComposerPhar}"

        Write-Output "@echo off"                     | Out-File -Encoding "ASCII" -Append $ComposerBatch
        Write-Output "${Php} `"${ComposerPhar}`" %*" | Out-File -Encoding "ASCII" -Append $ComposerBatch
    }
}

Function SetupPhpVersionString {
	$RemoteUrl = 'http://windows.php.net/downloads/releases/sha1sum.txt';
	$DestinationPath = "${Env:Temp}\php-sha1sum.txt"

	If (-not [System.IO.File]::Exists($DestinationPath)) {
		Write-Host "Downloading PHP SHA sums file: ${RemoteUrl} ..."
		DownloadFile $RemoteUrl $DestinationPath
	}

	$VersionString = Get-Content $DestinationPath | Where-Object {
		$_ -match "php-($Env:PHP_MINOR\.\d+)-src"
	} | ForEach-Object { $matches[1] }

	If ($VersionString -NotMatch '\d+\.\d+\.\d+') {
		Throw "Unable to obtain PHP version string using pattern 'php-($Env:PHP_MINOR\.\d+)-src'"
	 }

	$Env:PHP_VERSION = $VersionString
}

Function AppendSessionPath {
	$PathsCollection  = @("C:\Program Files (x86)\MSBuild\${Env:VC_VERSION}.0\Bin")
	$PathsCollection += "C:\Program Files (x86)\Microsoft Visual Studio ${Env:VC_VERSION}.0\VC"
	$PathsCollection += "C:\Program Files (x86)\Microsoft Visual Studio ${Env:VC_VERSION}.0\VC\bin"
	$PathsCollection += "${Env:PHP_SDK_PATH}\bin"
	$PathsCollection += "${Env:PHP_PATH}\bin"
	$PathsCollection += "${Env:PHP_PATH}"
	$PathsCollection += "${Env:APPVEYOR_BUILD_FOLDER}"

	$CurrentPath = (Get-Item -Path ".\" -Verbose).FullName

	ForEach ($PathItem In $PathsCollection) {
		Set-Location Env:
		$AllPaths = (Get-ChildItem Path).value.split(";")  | Sort-Object -Unique
		$AddToPath = $true

		ForEach ($AddedPath In $AllPaths) {
			If (-not "${AddedPath}") {
				continue
			}

			$AddedPath = $AddedPath -replace '\\$', ''

			If ($PathItem -eq $AddedPath) {
				$AddToPath = $false
			}
		}

		If ($AddToPath) {
			$Env:Path += ";$PathItem"
		}
	}

	Set-Location "${CurrentPath}"
}

Function Expand-Item7zip {
	Param(
		[Parameter(Mandatory=$true)][System.String] $Archive,
		[Parameter(Mandatory=$true)][System.String] $Destination
	)

	If (-not (Test-Path -Path $Archive -PathType Leaf)) {
		Throw "Specified archive File is invalid: [$Archive]"
	}

	If (-not (Test-Path -Path $Destination -PathType Container)) {
		New-Item $Destination -ItemType Directory | Out-Null
	}

	$Result = (& 7z x "$Archive" "-o$Destination" -aoa -bd -y -r)

	$7zipExitCode = $LASTEXITCODE
	If ($7zipExitCode -ne 0) {
		Throw "An error occurred while unzipping [$Archive] to [$Destination]. Exit code was [${7zipExitCode}]"
	}
}

Function DownloadFile {
	Param(
		[Parameter(Mandatory=$true)][System.String] $RemoteUrl,
		[Parameter(Mandatory=$true)][System.String] $DestinationPath
	)

	$RetryMax   = 5
	$RetryCount = 0
	$Completed  = $false

	$WebClient = New-Object System.Net.WebClient
	$WebClient.Headers.Add('User-Agent', 'AppVeyor PowerShell Script')

	While (-not $Completed) {
		Try {
			$WebClient.DownloadFile($RemoteUrl, $DestinationPath)
			$Completed = $true
		} Catch {
			If ($RetryCount -ge $RetryMax) {
				$ErrorMessage = $_.Exception.Message
				Write-Host "Error downloadingig ${RemoteUrl}: $ErrorMessage"
				$Completed = $true
			} Else {
				$RetryCount++
			}
		}
	}
}
