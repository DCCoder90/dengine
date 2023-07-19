cmake_minimum_required(VERSION 3.25)
project(Game)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 CONFIG REQUIRED)

add_executable(Game main.cpp LeafMan.cpp BaselevelBackground.cpp BaseLevel.cpp Player.cpp)

target_include_directories(Game PRIVATE ${CMAKE_SOURCE_DIR}/dengine/include)
target_link_libraries(Game PRIVATE dengine)
target_link_libraries(Game PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
        )

