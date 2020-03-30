# This file is part of Phalcon.
#
# (c) Phalcon Team <team@phalcon.io>
#
# For the full copyright and license information, please view
# the LICENSE file that was distributed with this source code.

function SetupCommonEnvironment {
    $CommonPath = "C:\Downloads", "C:\Downloads\Choco"

    foreach ($path in $CommonPath) {
        if (-not (Test-Path $path)) {
            New-Item -ItemType Directory -Force -Path $path | Out-Null
        }
    }

    # Hide "You are in 'detached HEAD' state" message
    git config --global advice.detachedHead false
    git config --global core.autocrlf false
}

function InstallPhpSdk {
    Write-Output "Install PHP SDK binary tools: ${env:PHP_SDK_VERSION}"

    $RemoteUrl = "https://github.com/microsoft/php-sdk-binary-tools/archive/php-sdk-${env:PHP_SDK_VERSION}.zip"
    $DestinationPath = "C:\Downloads\php-sdk-${env:PHP_SDK_VERSION}.zip"

    if (-not (Test-Path $env:PHP_SDK_PATH)) {
        if (-not [System.IO.File]::Exists($DestinationPath)) {
            Write-Output "Downloading PHP SDK binary tools: $RemoteUrl ..."
            DownloadFile $RemoteUrl $DestinationPath
        }

        $DestinationUnzipPath = "${env:Temp}\php-sdk-binary-tools-php-sdk-${env:PHP_SDK_VERSION}"

        if (-not (Test-Path "$DestinationUnzipPath")) {
            Expand-Item7zip $DestinationPath $env:Temp
        }

        Move-Item -Path $DestinationUnzipPath -Destination $env:PHP_SDK_PATH
    }
}

function DownloadPhpSrc {
    Write-Output "Download PHP Src: ${env:PHP_VERSION}"

    $RemoteUrl = "https://windows.php.net/downloads/releases/php-${env:PHP_VERSION}-src.zip"
    $RemoteArchiveUrl = "https://windows.php.net/downloads/releases/archives/php-${env:PHP_VERSION}-src.zip"
    $DestinationPath = "C:\Downloads\php-${env:PHP_VERSION}-src.zip"

    if (-not (Test-Path $env:PHP_SRC_PATH)) {
        if (-not [System.IO.File]::Exists($DestinationPath)) {
            Write-Output "Downloading PHP pack: ${RemoteUrl} ..."
            DownloadFile $RemoteUrl $DestinationPath
        }

        $DestinationUnzipPath = "${env:Temp}\php-${env:PHP_VERSION}-src"

        if (-not (Test-Path "$DestinationUnzipPath")) {
            try {
                Expand-Item7zip $DestinationPath $env:Temp
            } catch {
                # if expand fails try alternative download
                Write-Output "Downloading PHP pack from archive: ${RemoteArchiveUrl} ..."
                DownloadFile $RemoteArchiveUrl $DestinationPath
                Expand-Item7zip $DestinationPath $env:Temp
            }
        }

        Move-Item -Path $DestinationUnzipPath -Destination $env:PHP_SRC_PATH
    }
}

function InstallPhpDevPack {
    Write-Output "Install PHP Dev pack: ${env:PHP_VERSION}"

    $RemoteUrl = "https://windows.php.net/downloads/releases/php-devel-pack-${env:PHP_VERSION}-${env:BUILD_TYPE}-vc${env:VC_VERSION}-${env:PHP_ARCH}.zip"
    $RemoteArchiveUrl = "https://windows.php.net/downloads/releases/archives/php-devel-pack-${env:PHP_VERSION}-${env:BUILD_TYPE}-vc${env:VC_VERSION}-${env:PHP_ARCH}.zip"
    $DestinationPath = "C:\Downloads\php-devel-pack-${env:PHP_VERSION}-${env:BUILD_TYPE}-VC${env:VC_VERSION}-${env:PHP_ARCH}.zip"

    if (-not (Test-Path $env:PHP_DEVPACK)) {
        if (-not [System.IO.File]::Exists($DestinationPath)) {
            Write-Output "Downloading PHP Dev pack: ${RemoteUrl} ..."
            DownloadFile $RemoteUrl $DestinationPath
        }

        $DestinationUnzipPath = "${env:Temp}\php-${env:PHP_VERSION}-devel-VC${env:VC_VERSION}-${env:PHP_ARCH}"

        if (-not (Test-Path "$DestinationUnzipPath")) {
            try {
                Expand-Item7zip $DestinationPath $env:Temp
            } catch {
                # if expand fails try alternative download
                Write-Output "Downloading PHP Dev pack from archive: ${RemoteArchiveUrl} ..."
                DownloadFile $RemoteArchiveUrl $DestinationPath
                Expand-Item7zip $DestinationPath $env:Temp
            }
        }

        Move-Item -Path $DestinationUnzipPath -Destination $env:PHP_DEVPACK
    }
}


function Expand-Item7zip {
    param(
        [Parameter(Mandatory = $true)] [System.String] $Archive,
        [Parameter(Mandatory = $true)] [System.String] $Destination
    )

    if (-not (Test-Path -Path $Archive -PathType Leaf)) {
        throw "Specified archive File is invalid: [$Archive]"
    }

    if (-not (Test-Path -Path $Destination -PathType Container)) {
        New-Item $Destination -ItemType Directory | Out-Null
    }

    $Result = (& 7z x "$Archive" "-o$Destination" -aoa -bd -y -r)

    if ($LastExitCode -ne 0) {
        Write-Output "An error occurred while unzipping [$Archive] to [$Destination]. Error code was: ${LastExitCode}"
        Exit $LastExitCode
    }
}

function DownloadFileUsingAlternative {
    <#
        .SYNOPSIS
            Downloads files from URL using alternative ULR if primary URL not found
    #>

    [CmdletBinding()]
    param(
        [parameter(Mandatory = $true)] [ValidateNotNullOrEmpty()] [System.String] $RemoteUrl,
        [parameter(Mandatory = $true)] [ValidateNotNullOrEmpty()] [System.String] $RemoteArchiveUrl,
        [parameter(Mandatory = $true)] [ValidateNotNullOrEmpty()] [System.String] $DestinationPath,
        [parameter(Mandatory = $true)] [ValidateNotNullOrEmpty()] [System.String] $Message
    )

    try {
        Write-Output "${Message}: ${RemoteUrl} ..."
        DownloadFile $RemoteUrl $DestinationPath
    } catch [System.Net.WebException] {
        Write-Output "${Message} from archive: ${RemoteArchiveUrl} ..."
        DownloadFile $RemoteArchiveUrl $DestinationPath
    }
}

function DownloadFile {
    <#
        .SYNOPSIS
            Downloads file from providing URL to specified destionation.

        .NOTES
            Throws System.Net.WebException if $RequestUrl not found.
    #>

    [CmdletBinding()]
    param(
        [parameter(Mandatory = $true)] [ValidateNotNullOrEmpty()] [System.String] $RemoteUrl,
        [parameter(Mandatory = $true)] [ValidateNotNullOrEmpty()] [System.String] $DestinationPath
    )

    process {
        $RetryMax   = 5
        $RetryCount = 0
        $Completed  = $false

        $WebClient = New-Object System.Net.WebClient
        $WebClient.Headers.Add('User-Agent', 'GitHub Actions PowerShell Script')

        while (-not $Completed || $RetryCount -eq $RetryMax) {
            try {
                $WebClient.DownloadFile($RemoteUrl, $DestinationPath)
                $Completed = $true
            } catch [System.Net.WebException] {
                $ErrorMessage = $_.Exception.Message

                if ($_.Exception.Response.StatusCode -eq 404) {
                    Write-Warning -Message "Error downloading ${RemoteUrl}: $ErrorMessage"
                    throw [System.Net.WebException] "Error downloading ${RemoteUrl}"
                }

                if ($RetryCount -ge $RetryMax) {
                    Write-Output "Error downloading ${RemoteUrl}: $ErrorMessage"
                    $Completed = $true
                } else {
                    $RetryCount++
                }
            }
        }
    }
}

function PrintLogs {
    $Logs = "${env:GITHUB_WORKSPACE}\compile-errors.log",
            "${env:GITHUB_WORKSPACE}\compile.log",
            "${env:GITHUB_WORKSPACE}\ext\configure.js"

    foreach ($logFile in $Logs) {
        if (Test-Path -Path $logFile) {
            Get-Content -Path $logFile
        }
    }
}

function PrintEnvVars {
    Write-Output ($env:Path).Replace(';', "`n")
    Get-ChildItem env:
}

function PrintDirectoriesContent {
    Get-ChildItem -Path "${env:GITHUB_WORKSPACE}"

    $ReleasePath = Split-Path -Path "${env:RELEASE_DLL_PATH}"
    $BuildPath = Split-Path -Path "${ReleasePath}"

    $Directories =  "C:\Downloads",
                    "C:\Projects",
                    "${env:PHPROOT}\ext",
                    ${ReleasePath},
                    ${BuildPath}

    foreach ($dir in $Directories) {
        if (Test-Path -Path $dir) {
            Get-ChildItem -Path $dir
        }
    }
}

# TODO(klay): Add phpize and phpconfig here
function PrintPhpInfo {
    $IniFile = "${env:PHPROOT}\php.ini"
    $PhpExe = "${env:PHPROOT}\php.exe"

    if (Test-Path -Path "${PhpExe}") {
        Write-Output ""
        & "${PhpExe}" -v

        Write-Output ""
        & "${PhpExe}" -m

        Write-Output ""
        & "${PhpExe}" -i
    } elseif (Test-Path -Path "${IniFile}") {
        Get-Content -Path "${IniFile}"
    }
}

function PrintBuildDetails {
    $BuildDate = Get-Date -Format g

    Write-Output "Build date: ${BuildDate}"
    Write-Output "Git commit: ${env:GITHUB_SHA}"
    Write-Output "Target PHP version: ${env:PHP_MINOR}"
    Write-Output "PHP SDK Toolset Version: ${env:PHP_SDK_VC_TOOLSET_VER}"
    Write-Output "Build Worker Image Version: ${env:ImageVersion}"
    Write-Output "Processor ID: ${env:PROCESSOR_IDENTIFIER}"
    Write-Output "Processor Architecture: ${env:PROCESSOR_ARCHITECTURE}"
    Write-Output "Number of Processors: ${env:NUMBER_OF_PROCESSORS}"
    Write-Output "Visual Studio Version: ${env:VisualStudioVersion}"
    Write-Output "Host Architecture: ${env:VSCMD_ARG_HOST_ARCH}"
    Write-Output "Target Architecture: ${env:VSCMD_ARG_TGT_ARCH}"
    Write-Output "VC Tools Version: ${env:VCToolsVersion}"
    Write-Output "Windows SDK Version: ${env:WindowsSDKVersion}"
}


function InitializeReleaseVars {
    if ($env:BUILD_TYPE -Match "nts-Win32") {
        $env:RELEASE_ZIPBALL = "${env:PACKAGE_PREFIX}_${env:PHP_ARCH}_vc${env:VC_VERSION}_php${env:PHP_MINOR}_nts"

        if ($env:PHP_ARCH -eq 'x86') {
            $env:RELEASE_FOLDER = "Release"
        } else {
            $env:RELEASE_FOLDER = "x64\Release"
        }
    } else {
        $env:RELEASE_ZIPBALL = "${env:PACKAGE_PREFIX}_${env:PHP_ARCH}_vc${env:VC_VERSION}_php${env:PHP_MINOR}"

        if ($env:PHP_ARCH -eq 'x86') {
            $env:RELEASE_FOLDER = "Release_TS"
        } else {
            $env:RELEASE_FOLDER = "x64\Release_TS"
        }
    }

    $env:RELEASE_DLL_PATH = "${env:PHP_PECL_PATH}\phalcon\phalcon-${env:PHALCON_VERSION}\${env:RELEASE_FOLDER}\${env:EXTENSION_FILE}"

    Write-Output "::set-env name=RELEASE_ZIPBALL::${env:RELEASE_ZIPBALL}"
    Write-Output "::set-env name=RELEASE_DLL_PATH::${env:RELEASE_DLL_PATH}"
}

function EnablePhalconExtension {
    if (-not (Test-Path env:RELEASE_DLL_PATH)) {
        InitializeReleaseVars
    }

    if (-not (Test-Path "${env:RELEASE_DLL_PATH}")) {
        throw "Unable to locate extension path: ${env:RELEASE_DLL_PATH}"
    }

    Copy-Item "${env:RELEASE_DLL_PATH}" "${env:PHPROOT}\ext\${env:EXTENSION_FILE}"

    Enable-PhpExtension -Extension "${env:EXTENSION_NAME}" -Path "${env:PHPROOT}"
}
