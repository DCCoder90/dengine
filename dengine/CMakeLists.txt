cmake_minimum_required(VERSION 3.25)
project(DENGINE)

set(CMAKE_CXX_STANDARD 17)
set(SDL2_INCLUDE_DIR C:/libs/SDL/x86_64-w64-mingw32/include/SDL2)
set(SDL2_LIB_DIR C:/libs/SDL/x86_64-w64-mingw32/lib)

list(APPEND CMAKE_PREFIX_PATH "C:/Program Files/zlib")
find_package(ZLIB REQUIRED)

if (ZLIB_FOUND)
    include_directories(${ZLIB_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "zlib not found")
endif()

set(SDL2_IMG_INCLUDE_DIR C:/libs/SDL_IMG/x86_64-w64-mingw32/include/SDL2)
set(SDL2_IMG_LIB_DIR C:/libs/SDL_IMG/x86_64-w64-mingw32/lib)


include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMG_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR} ${SDL2_IMG_LIB_DIR})

find_package(SDL2_ttf CONFIG REQUIRED)

add_executable(DENGINE
        main.cpp
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
        Game/BaseLevel.cpp
        Game/LeafMan.cpp
        lib/Components/Sprite.cpp
        Game/Player.cpp
        lib/Helpers.cpp
        lib/System/Sound.cpp
        lib/System/Camera.cpp
        lib/System/CameraManager.cpp
        lib/Utils/NanoLog.cpp
        lib/System/AudioManager.cpp
        lib/Components/SpriteSheet.cpp
        Game/BaselevelBackground.cpp
        lib/UI/UI.cpp
        lib/UI/UIWindow.cpp
        lib/UI/Components/ProgressBarV.cpp
        lib/UI/UIComponent.cpp
        lib/UI/Components/ProgressBarH.cpp
        lib/UI/FontManager.cpp
        lib/UI/Components/Text.cpp)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2 $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static> SDL2_image ${ZLIB_LIBRARIES})