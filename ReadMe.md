## SDL Fun

This is just a repo where I can store stuff as I'm learning [SDL](https://www.libsdl.org/) and trying to write a game from scratch in C++.  

In order to compile this you will need [SDL](https://github.com/libsdl-org/SDL/releases/tag/release-2.26.5), ensure that the paths in the [CMakeLists.txt](CMakeLists.txt) file are pointing to where your files are, and also copy the dll to the directory with the final executable.  I plan on automating that last part at some point, just not right now.


### Notebook

If ```SDL_MAIN_HANDLED``` is not defined at the top of [main.cpp](main.cpp) then it will throw the following error:

>undefined reference to `WinMain'

**Fix**
```c++
#define SDL_MAIN_HANDLED
```

Using SDL for image rendering.  Necessary files can be found [here](https://github.com/libsdl-org/SDL_image/releases)