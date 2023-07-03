## dEngine

I am working on furthering my skills with C++ and in the process I decided to learn it by writing a simple little game engine.  This will allow me to gain more experience not only in C++ development but in graphic rendering, audio management, etc etc.  

This repo may get messy at times while I'm working on it, as I'm just throwing stuff around.  Typically I'm not this messy, but since it's for my own eyes really and learning experience, why not?

I'm going to do my best to ensure the main branch always compiles and runs.  I'll continue documenting various aspects of the project overtime as well.

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

### TODO

* Video System
* Event System
* UI System
* Save/Load system