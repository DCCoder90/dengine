//
// Created by ernes on 6/24/2023.
//

#ifndef SDL_LEARN_GAMESTATES_H
#define SDL_LEARN_GAMESTATES_H
enum GAMESTATES{
    Splash,
    Playing,
    Gameover
};

class GameState {
public:
    GameState();
    ~GameState();
    int getGameState();
    void setGameState(int state);
private:
    int currentstate = GAMESTATES::Splash;
};
#endif //SDL_LEARN_GAMESTATES_H
