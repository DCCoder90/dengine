cmake_minimum_required(VERSION 3.25)
project(packer_util)

set(CMAKE_CXX_STANDARD 17)

# Specify the path to the zlib library
list(APPEND CMAKE_PREFIX_PATH "C:/Program Files/zlib")

# Find the zlib library
find_package(ZLIB REQUIRED)

if (ZLIB_FOUND)
    include_directories(${ZLIB_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "zlib not found")
endif()

# Add your source files
add_executable(packer_util main.cpp Packer.cpp Packer.h CLIArg.cpp CLIArg.h)

# Link the zlib library to your executable
target_link_libraries(packer_util ${ZLIB_LIBRARIES})