@echo off
setlocal

SET SCRIPT_DIR=%~dp0
cscript.exe %SCRIPT_DIR%create_release_src_files.js

endlocal