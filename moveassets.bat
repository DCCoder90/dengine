@echo off
@RD /S /Q "cmake-build-debug/Assets"
robocopy Assets cmake-build-debug/Assets /E
robocopy bin/ cmake-build-debug/ /E
