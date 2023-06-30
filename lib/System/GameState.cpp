
#include "../../include/System/GameStates.h"

GameState GameState::instance;

GameState::GameState() {

}

GameState::~GameState() {

}

int GameState::getGameState() {
    return currentstate;
}

void GameState::setGameState(int state) {
    currentstate = state;
}

GameState& GameState::GetInstance() {
    return instance;
}