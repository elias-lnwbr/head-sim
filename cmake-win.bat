@ECHO off
SETLOCAL enabledelayedexpansion
COLOR B


REM CHECK ADMIN MODE
net session >NUL 2>&1
IF NOT %errorLevel% == 0 (
    REM REQUEST ADMIN MODE IF NEEDED
    if not "%1"=="am_admin" (powershell start -verb runas '%0' am_admin & exit /b)
)

REM SET GLOBALS
FOR /F "tokens=* USEBACKQ" %%F IN (`where cmake`) DO SET CMAKEPATH=%%F
CD /D %~dp0

SET ROOT=%cd%
SET LIBPATH=%cd%\..\deps\glfw
FOR /F "usebackq tokens=*" %%i IN (`vswhere -latest -requires Microsoft.Component.MSBuild -find MSBuild\**\Bin\MSBuild.exe`) DO SET VSPATH=%%i

REM CHECK VS AND CMAKE PATHS
IF NOT DEFINED VSPATH (
    COLOR 4
    ECHO "failed to locate msbuild tools."
    PAUSE
    EXIT 2
)

IF NOT DEFINED CMAKEPATH (
    COLOR 4
    echo "failed to locate cmake. Please set cmake path in environment variable."
    PAUSE
    EXIT 3
)




REM //BUILDING//

REM BUILD LIB
echo Building shapelib
mkdir %LIBPATH%\build > NUL 2>&1
CD %LIBPATH%\build

echo building shapelib x64...
cmake -G "Visual Studio 16 2019" -A x64 %LIBPATH%
IF NOT %errorLevel% == 0 ECHO failed to generate vs files for shapelib.

echo compiling shapelib for Release x64...
"%VSPATH%" shp.vcxproj /t:build /p:Configuration="Release" /p:Platform="x64" /p:BuildInParallel=true /p:OutDir=%LIBPATH%\build\Release
IF NOT %errorLevel% == 0 ECHO failed to compile shapelib.

echo compiling shapelib for Debug x64...
"%VSPATH%" shp.vcxproj /t:build /p:Configuration="Debug" /p:Platform="x64" /p:BuildInParallel=true /p:OutDir=%LIBPATH%\build\Debug
IF NOT %errorLevel% == 0 ECHO failed to compile shapelib.
