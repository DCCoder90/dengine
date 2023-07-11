@echo off
@RD /S /Q "cmake-build-debug/Assets"
robocopy Assets cmake-build-debug/Assets /E
robocopy extern/lib/rmlui/debug cmake-build-debug/ /E
robocopy extern/bin/sdl cmake-build-debug/ /E
robocopy extern/bin/sdl_img cmake-build-debug/ /E
robocopy extern/lib/freetype cmake-build-debug/ /E

