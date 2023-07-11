cmake_minimum_required(VERSION 3.25)
project(DENGINE)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_PREFIX_PATH "C:/vcpkg")

find_package(ZLIB REQUIRED)
find_package(Freetype REQUIRED)
find_package(RmlUi REQUIRED)
add_library(RmlUi::RmlUi INTERFACE IMPORTED)
set_target_properties(RmlUi::RmlUi PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${RmlUi_INCLUDE_DIRS}"
        )
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)

if (ZLIB_FOUND)
    include_directories(${ZLIB_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "zlib not found")
endif()

if (SDL2_FOUND)
    include_directories(${SDL2_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "SDL2 not found")
endif()

if (SDL2_image_FOUND)
    include_directories(${SDL2_image_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "SDL2_image not found")
endif()

if (Freetype_FOUND)
    include_directories(${Freetype_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Freetype not found")
endif()

if (RmlUi_FOUND)
    include_directories(${RmlUi_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "RmlUi not found")
endif()

if (SDL2_ttf_FOUND)
    include_directories(${SDL2_ttf_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "SDL2_ttf not found")
endif()

add_executable(DENGINE main.cpp
        lib/System/Time.cpp
        lib/System/Game.cpp
        lib/System/GameObject.cpp
        lib/System/Component.cpp
        lib/Components/InputController.cpp
        lib/System/GameState.cpp
        lib/System/EventSystem.cpp
        lib/Components/Collider.cpp
        lib/Vec2.cpp
        lib/System/GameLevel.cpp
        game/baseLevel/BaseLevel.cpp
        game/enemies/LeafMan.cpp
        lib/Components/Sprite.cpp
        lib/Helpers.cpp
        lib/System/Sound.cpp
        lib/System/Camera.cpp
        lib/System/CameraManager.cpp
        lib/Utils/NanoLog.cpp
        lib/System/AudioManager.cpp
        lib/Components/SpriteSheet.cpp
        game/baseLevel/BaselevelBackground.cpp
        game/Hud.cpp
        lib/RmlUi_Renderer_SDL.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)

target_link_libraries(${PROJECT_NAME} PRIVATE
        SDL2::SDL2main
        SDL2::SDL2
        SDL2_image::SDL2_image
        SDL2_ttf::SDL2_ttf
        Freetype::Freetype
        ZLIB::ZLIB
        RmlUi::RmlUi)