@echo off
@RD /S /Q "cmake-build-debug/Assets"
robocopy Assets cmake-build-debug/Assets /E
robocopy extern/bin/rmlui cmake-build-debug/ /E
robocopy extern/bin/sdl cmake-build-debug/ /E
robocopy extern/bin/sdl_img cmake-build-debug/ /E

