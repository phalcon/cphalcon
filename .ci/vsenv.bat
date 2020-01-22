@echo off
rem This file is part of Phalcon.
rem
rem (c) Phalcon Team <team@phalcon.io>
rem
rem For the full copyright and license information, please view
rem the LICENSE file that was distributed with this source code.
cls

rem For more see: https://github.com/microsoft/vswhere/wiki/Find-VC
rem
rem For the software installed on GitHub-hosted runners see:
rem https://help.github.com/en/actions/automating-your-workflow-with-github-actions/software-installed-on-github-hosted-runners
rem
echo "Find VC..."
SET VSWHERE="C:\Program Files (x86)\Microsoft Visual Studio\Installer\vswhere"

for /f "usebackq tokens=*" %%i in (`%VSWHERE% -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do (
  set InstallDir=%%i
)

if exist "%InstallDir%\Common7\Tools\vsdevcmd.bat" (
  echo "Found %InstallDir%\Common7\Tools\vsdevcmd.bat"
  call "%InstallDir%\Common7\Tools\vsdevcmd.bat" %*
) else "VC not found"

echo "------------- phpsdk-starter ---------------------------"
call "%PHP_SDK_PATH%\phpsdk-vs16-%PHP_ARCH%.bat"

echo "------------- phpsdk_setvars ---------------------------"
call "%PHP_SDK_PATH%\bin\phpsdk_setvars.bat"

rem Loop over all environment variables and make them global using set-env.
rem
rem See: https://help.github.com/en/articles/development-tools-for-github-actions#set-an-environment-variable-set-env
rem See: https://stackoverflow.com/questions/39183272/loop-through-all-environmental-variables-and-take-actions-depending-on-prefix
setlocal
for /f "delims== tokens=1,2" %%a in ('set') do (
  echo ::set-env name=%%a::%%b
)
endlocal
