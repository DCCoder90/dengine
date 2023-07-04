## How do I implement game saving?
This is something that I've been trying to figure out for a while and is currently being tracked by [this issue](https://github.com/DCCoder90/dengine/issues/12), but as of this writing it hasn't been done.  As of now you will have to write the save and load functions yourself.


## How do I make it so I can pause the game?

In order to pause the game, the implementation will be on the game itself rather than being handled by the engine.  In order to do this the GameState class should be used.  The GameLevel.h includes abstract functions of:

```cpp
        /**
     * @brief Pauses the game
     */
        virtual void Pause() = 0;

        /**
         * @brief Resumes the game
         */
        virtual void Resume() = 0;
```

These should be overridden by your level and implemented as such:

```cpp
void BaseLevel::Pause(){
    GameState::GetInstance().setGameState(GAMESTATES::Pause);
}
void BaseLevel::Resume(){
    GameState::GetInstance().setGameState(GAMESTATES::Playing);
}
```

Then in your objects' update functions you can check the state to stop movement, rendering or anything as such:

```cpp
    if(GameState::GetInstance().getGameState()==GAMESTATES::Pause){
        return;
    }
```