//
// Created by ernes on 6/24/2023.
//
#include "../../include/System/GameStates.h"

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