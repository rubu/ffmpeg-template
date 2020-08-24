@echo off

REM set Visual Studio build directory and generator (if not using Visual Studio 2019 fix these)
set vs_build_dir=build-vs-2019
set vs_generator="Visual Studio 16 2019"

if not exist %vs_build_dir% (
    mkdir %vs_build_dir%
)

cd %vs_build_dir%

REM since it is not guaranteed that the proper terminal will be run, it would be better
REM to actually verify cmake path
if exist "C:\Program Files\CMake\bin\cmake.exe" (
    "C:\Program Files\CMake\bin\cmake.exe" -G %vs_generator% ..
) else (
    REM rely on cmake being in path
    cmake.exe -G %vs_generator% ..
)