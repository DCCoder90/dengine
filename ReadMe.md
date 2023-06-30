## SDL Fun

This is just a repo where I can store stuff as I'm learning [SDL](https://www.libsdl.org/) and trying to write a game from scratch in C++.  

In order to compile this you will need [SDL](https://github.com/libsdl-org/SDL/releases/tag/release-2.26.5), ensure that the paths in the [CMakeLists.txt](CMakeLists.txt) file are pointing to where your files are, and also copy the dll to the directory with the final executable.  I plan on automating that last part at some point, just not right now.


## Structure

|Directory|Purpose|
|---|---|
|Game|Header and Source files for game|
|include|Header Files|
|lib|Source Files|
|bin|Build dependency binaries|
|Assets|Graphics/Audio/Etc for game|
|.run|IDE Configuration|

### Notebook

If ```SDL_MAIN_HANDLED``` is not defined at the top of [main.cpp](main.cpp) then it will throw the following error:

>undefined reference to `WinMain'

**Fix**
```c++
#define SDL_MAIN_HANDLED
```

#### 6cdb99e
Using SDL for image rendering.  Necessary files can be found [here](https://github.com/libsdl-org/SDL_image/releases)

Thanks to [LepleyDev](https://www.youtube.com/@LepleyDev) for the work he did on "Making a Game in C++ and SDL2" series.  Helped with rendering an image and fixing stuff up a bit.

#### 9463e6a

Created the moveassets.bat file to automatically copy the Assets directory and all files in the bin directory to the debug output.  Keeps issues to a minimum.
Also created the enemy class and added it to the game.

#### N/A

Just wanted to quickly notate that the full path in the .run/GenerateDocumentation.xml file could potentially cause issues if the project is moved between systems.  Will need to take care of that at some point in the future.

Before I can continue to move forward with this I have to look into event handling.  Want to move the collision detection from Game.cpp to a collider component.