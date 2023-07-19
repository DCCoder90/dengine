cmake_minimum_required(VERSION 3.25)
project(DENGINE)

set(CMAKE_CXX_STANDARD 17)

find_package(ZLIB REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)

include_directories(${ZLIB_INCLUDE_DIRS})
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMG_INCLUDE_DIR})

add_library(DENGINE SHARED
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
        lib/Components/Sprite.cpp
        lib/Helpers.cpp
        lib/System/Sound.cpp
        lib/System/Camera.cpp
        lib/System/CameraManager.cpp
        lib/Utils/NanoLog.cpp
        lib/System/AudioManager.cpp
        lib/Components/SpriteSheet.cpp
        lib/UI/UI.cpp
        lib/UI/UIWindow.cpp
        lib/UI/Components/ProgressBarV.cpp
        lib/UI/Components/ProgressBarH.cpp
        lib/UI/FontManager.cpp
        lib/UI/Components/Text.cpp
        lib/UI/Components/RoundedBox.cpp
        lib/UI/Components/HollowRect.cpp
        lib/UI/Components/Circle.cpp
        lib/UI/Components/FilledCircle.cpp)

target_link_libraries(${PROJECT_NAME}
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
        $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>
        $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<$<BOOL:${WIN32}>:${CMAKE_DL_LIBS}>
        )