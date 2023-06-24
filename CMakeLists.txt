cmake_minimum_required(VERSION 3.25)
project(SDL_Learn)

set(CMAKE_CXX_STANDARD 17)
set(SDL2_INCLUDE_DIR C:/libs/SDL/x86_64-w64-mingw32/include/SDL2)
set(SDL2_LIB_DIR C:/libs/SDL/x86_64-w64-mingw32/lib)

set(SDL2_IMG_INCLUDE_DIR C:/libs/SDL_IMG/x86_64-w64-mingw32/include/SDL2)
set(SDL2_IMG_LIB_DIR C:/libs/SDL_IMG/x86_64-w64-mingw32/lib)


include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMG_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR} ${SDL2_IMG_LIB_DIR})

add_executable(SDL_Learn main.cpp lib/Player/Player.cpp include/Player/Player.h lib/System/Time.cpp include/System/Time.h lib/System/Game.cpp include/System/Game.h lib/System/Sprite.cpp include/System/Sprite.h lib/Player/Enemy.cpp include/Player/Enemy.h lib/Player/Character.cpp include/Player/Character.h lib/System/GameObject.cpp include/System/GameObject.h lib/System/Component.cpp include/System/Component.h include/System/GameStates.h lib/Components/InputController.cpp include/Components/InputController.h lib/System/GameState.cpp)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2_image)
