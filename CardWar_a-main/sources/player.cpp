#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include "player.hpp"

using namespace std;
using namespace ariel; 

// some_header_file.h
// #ifndef player.h
// #define player.h


string Player::getName() { return this->name;  }
int Player::getSumpnt(){ return this->sumpoint; }
int Player::card(){ return this->crd; }

void Player::setCrd(int num){
    this->crd = num;
}
// // Coinstructors:
Player::Player() {
    // std::cout << "Player()" << std::endl; 
    this->name = "None";
    this->stksize = 26;
    this->tken = 0;
    this->sumpoint = 0;
    this->crd = -1;
}
Player::Player(string n) { 
    // std::cout << "Player(string)" << std::endl; 
    this->name =  n; 
    this->stksize = 26;
    this->tken = 0;
    this->sumpoint = 0;
    this->crd = -1;
}

int Player::stacksize(){
    return this->stksize;
}

int Player::cardesTaken(){
    return this->tken;
}

// your code
// #endif