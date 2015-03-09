@echo off
setlocal

SET SCRIPT_DIR=%~dp0
cscript.exe %SCRIPT_DIR%update-project.js

endlocal