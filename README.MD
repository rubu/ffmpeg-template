* Overview *

This is a boilerplate repo for anything cross-platform that requires ffmpeg

* Bootstrapping with Visual Studio Code *

The repo contains a vs-code.code-workspace file which is a workspace containing bootstrapping tasks for all operating systems. It depends
on vcpkg to pull in the dependencies.

** Windows with Visual Studio 2019 **

The following prerequisites should be installed:

1. Visual Studio 2019
2. CMake

On Windows the bootstrapping task setup-windows invokes building vcpkg.exe if it does not exist and then installing ffmpeg with that. The platform (x86-windows vs x64-windows) will
be detected by the script and the appropriate ffmpeg version will be installed. After the setup-windows task has been successfully executed the setup-vs-build task can be run,
which will generate a Visual Studio solution in folder build-vs-2019 (the script uses Visual Studio 16 2019 generator by default, if needed adjust that). After this the build-vs-2019
should contain a ffmpeg-boilerplate.sln Visual Studio solution file which can be used for editing and developing using Visual Studio