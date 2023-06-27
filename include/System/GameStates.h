//
// Created by ernes on 6/24/2023.
//

#ifndef SDL_LEARN_GAMESTATES_H
#define SDL_LEARN_GAMESTATES_H

/** @enum GAMESTATES
*  @brief Available game states
*/
enum GAMESTATES{
    Splash,
    Playing,
    Gameover
};

/**
 *  GameState is used to manage the current state of the game as a whole.  A few game states that are built in
 *  reference whether the game is currently being played, at the gameover screen, or at the flash screen.
 */
class GameState {
public:
    GameState();
    ~GameState();
    /**
     * Retrieve the current gamestate
     * @see GAMESTATES
     * @return int that corrosponds to a game state in GAMESTATES
     */
    int getGameState();
    /**
     * Set the game state.  This can be done with an int or with the GAMESTATES enum.
     * @see GAMESTATES
     * @param state The current state of the game
     */
    void setGameState(int state);
private:
    int currentstate = GAMESTATES::Splash;
};
#endif //SDL_LEARN_GAMESTATES_H