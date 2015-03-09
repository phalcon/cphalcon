Building Phalcon In Windows 
===========================

1. Figure out which version of PHP you are using and whether thread safety is enabled.
2. Go to http://windows.php.net/downloads/releases/archives/ and download the php-devel-pack for your version and thread safety.
3. Extract the contents to the \dependencies\php\ subdirectory of this directory.  You should have this directory structure now:
```\win32
\win32\dependencies
\win32\dependencies\php
\win32\dependencies\php\build
\win32\dependencies\php\include
\win32\dependencies\php\lib
\win32\dependencies\php\script
\win32\dependencies\php\phpize.bat
```
4. Open cphalcon.sln in Visual Studio 2008
5. Select configuration that matches your thread safety
6. Build and enjoy

Updating the project when files are added or removed from /dev
==============================================================

In the /win32/scripts directory, there is an update-project.bat batch file that will scan the /dev directory and update cphalcon.vproj.

Building the Release configs
==============================================================

Do not edit the files in the /release directory.  Instead edit the files in the dev directory.  When you want to build the release config, run the create-release-src-files.bat batch file in /win32/scripts.  That will rejoin (almost) all the files in /dev and create the files in /release.