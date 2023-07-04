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

add_executable(DENGINE main.cpp lib/System/Time.cpp include/System/Time.h lib/System/Game.cpp include/System/Game.h lib/System/GameObject.cpp include/System/GameObject.h lib/System/Component.cpp include/System/Component.h include/System/GameStates.h lib/Components/InputController.cpp include/Components/InputController.h lib/System/GameState.cpp lib/System/EventSystem.cpp include/System/EventSystem.h lib/Components/Collider.cpp include/Components/Collider.h lib/Vec2.cpp include/Vec2.h lib/System/GameLevel.cpp include/System/GameLevel.h Game/BaseLevel.cpp Game/BaseLevel.h Game/LeafMan.cpp Game/LeafMan.h lib/Components/Sprite.cpp include/Components/Sprite.h Game/Player.cpp Game/Player.h lib/Helpers.cpp lib/System/Sound.cpp include/System/Sound.h lib/System/Camera.cpp include/System/Camera.h lib/System/CameraManager.cpp include/System/CameraManager.h lib/Utils/NanoLog.cpp include/Utils/NanoLog.h include/Universal.h lib/System/AudioManager.cpp include/System/AudioManager.h lib/Components/SpriteSheet.cpp include/Components/SpriteSheet.h Game/BaselevelBackground.cpp Game/BaselevelBackground.h lib/Serializer.cpp include/Serializer.h)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2_image ${ZLIB_LIBRARIES})