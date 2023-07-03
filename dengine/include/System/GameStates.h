#ifndef DENGINE_GAMESTATES_H
#define DENGINE_GAMESTATES_H

namespace dengine {
/** @enum GAMESTATES
*  @brief Available game states
*/
    enum GAMESTATES {
        Splash,
        Playing,
        Gameover,
        Quit
    };

/**
 * @brief Manges and stores the current state of the game
 *  GameState is used to manage the current state of the game as a whole.  A few game states that are built in
 *  reference whether the game is currently being played, at the gameover screen, or at the flash screen.
 */
    class GameState {
    public:
        GameState();

        ~GameState();

        /**
         * @brief Retrieve the current gamestate
         * @see GAMESTATES
         * @return int that corrosponds to a game state in GAMESTATES
         */
        int getGameState();

        /**
         * @brief Set the game state.  This can be done with an int or with the GAMESTATES enum.
         * @see GAMESTATES
         * @param state The current state of the game
         */
        void setGameState(int state);

        static GameState &GetInstance();

    private:
        int currentstate = GAMESTATES::Splash;
        static GameState instance;
    };
}
#endif //DENGINE_GAMESTATES_H
