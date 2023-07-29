cmake_minimum_required(VERSION 3.25)
project(Game)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)

file(COPY
        ${CMAKE_SOURCE_DIR}/examples/Game/Assets
        DESTINATION ${CMAKE_BINARY_DIR}/examples/Game/
        )

add_executable(Game main.cpp LeafMan.cpp Player.cpp Level1/BaseLevel.cpp Level1/BaselevelBackground.cpp)

target_include_directories(Game PRIVATE ${CMAKE_SOURCE_DIR}/dengine/include)
target_link_libraries(Game PRIVATE DENGINE
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
        $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        )

add_custom_command(TARGET Game POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:DENGINE>
        $<TARGET_FILE_DIR:Game>
        )