# This file is part of the Phalcon Framework.
#
# (c) Phalcon Team <team@phalcon.io>
#
# For the full copyright and license information, please view
# the LICENSE.txt file that was distributed with this source code.

function InitializeBuildVars {
	switch ($Env:VC_VERSION) {
		'14' {
			if (-not (Test-Path $Env:VS120COMNTOOLS)) {
				throw 'The VS120COMNTOOLS environment variable is not set. Check your MS VS installation'
			}
			$Env:VSCOMNTOOLS = $Env:VS120COMNTOOLS -replace '\\$', ''

			break
		}
		'15' {
			if (-not (Test-Path $Env:VS140COMNTOOLS)) {
				throw 'The VS140COMNTOOLS environment variable is not set. Check your MS VS installation'
			}
			$Env:VSCOMNTOOLS = $Env:VS140COMNTOOLS -replace '\\$', ''
			break
		}
		default {
			throw 'This script is designed to run with MS VS 14/15. Check your MS VS installation'
			break
		}
	}

	if ($Env:PLATFORM -eq 'x64') {
		$Env:ARCH = 'x86_amd64'
	} else {
		$Env:ARCH = 'x86'
	}

	$SearchFilter = 'vcvarsall.bat'
	$SearchInFolder = "${Env:VSCOMNTOOLS}\..\..\"

	$Env:VCVARSALL_FILE = Get-ChildItem -Path $SearchInFolder -Filter $SearchFilter -Recurse -ErrorAction SilentlyContinue |
	ForEach-Object { $_.FullName }
}

function InitializeReleaseVars {
	if ($Env:BUILD_TYPE -Match "nts-Win32") {
		$Env:RELEASE_ZIPBALL = "phalcon_${Env:PLATFORM}_vc${Env:VC_VERSION}_php${Env:PHP_VERSION}_${Env:APPVEYOR_BUILD_VERSION}_nts"

		if ($Env:PLATFORM -eq 'x86') {
			$Env:RELEASE_FOLDER = "Release"
		} else {
			$Env:RELEASE_FOLDER = "x64\Release"
		}
	} else {
		$Env:RELEASE_ZIPBALL = "phalcon_${Env:PLATFORM}_vc${Env:VC_VERSION}_php${Env:PHP_VERSION}_${Env:APPVEYOR_BUILD_VERSION}"

		if ($Env:PLATFORM -eq 'x86') {
			$Env:RELEASE_FOLDER = "Release_TS"
		} else {
			$Env:RELEASE_FOLDER = "x64\Release_TS"
		}
	}

	$Env:RELEASE_DLL_PATH = "${Env:APPVEYOR_BUILD_FOLDER}\build\php7\safe\${Env:RELEASE_FOLDER}\php_phalcon.dll"
}
