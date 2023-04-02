#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include "game.hpp"

using namespace std;
using namespace ariel;      
            
            
Player Game::getp1() { return this->p1;  }
Player Game::getp2() { return this->p2;  } 

std::string to_string();

// // Constructors:
Game::Game() {
    std::cout << "Game()" << std::endl; 
    this->p1 = Player("None1"); 
    this->p2 =  Player("None2");
}
Game::Game(Player pl1, Player pl2) { 
    // std::cout << "Player(string)" << std::endl; 
    this->p1 =  pl1; 
    this->p2 = pl2;
}

int Game::printLastTurn(){
    cout<<"";
    return 0;
}

void Game::playTurn(){
    cout<<"";
}

void Game::playAll(){

}

int Game::printWiner(){
    cout<<"Winner";
    return 0;
}

int Game::printLog(){
    return 0;
}

int Game::printStats(){
    return 0;
}