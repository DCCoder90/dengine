cmake_minimum_required(VERSION 3.25)
project(packer_util)

set(CMAKE_CXX_STANDARD 17)

add_executable(packer_util main.cpp Packer.cpp Packer.h CLIArg.cpp CLIArg.h)
