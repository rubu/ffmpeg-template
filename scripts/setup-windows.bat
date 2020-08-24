if not exist .\vcpkg\vcpkg.exe (
    .\vcpkg\bootstrap-vcpkg.bat
)

reg Query "HKLM\Hardware\Description\System\CentralProcessor\0" | find /i "x86" > NUL && set OS=32BIT || set OS=64BIT

if %OS%==32BIT then
    .\vcpkg\vcpkg install ffmpeg:x86-windows
else
    .\vcpkg\vcpkg install ffmpeg:x64-windows