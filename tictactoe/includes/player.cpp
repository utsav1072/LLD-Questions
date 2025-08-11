#include "player.h"

Player::Player(const string &name, int id){
    this->name = name;
    this->id = id;
}

string Player::showName(){
    return this->name;
}