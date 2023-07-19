cmake_minimum_required(VERSION 3.25)
project(GAME_ENGINE)

set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

add_subdirectory(dengine)
add_subdirectory(packer-util)
add_subdirectory(examples/Game)

file(COPY
        ${CMAKE_CURRENT_BINARY_DIR}/vcpkg_installed/x64-windows/bin/
        DESTINATION ${CMAKE_BINARY_DIR}/examples/Game
        FILES_MATCHING
        PATTERN "*.dll"
        )