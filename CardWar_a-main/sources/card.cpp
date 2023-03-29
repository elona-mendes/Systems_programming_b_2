#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include "card.hpp"

// some_header_file.h
// #ifndef CARD_H
// #define CARD_H

using namespace std;
using namespace ariel;

int Card::getCard(){
    srand(time(0)); 
    this->c = (rand() % 52) + 1;
    return this->c;
}
//need to check that card aren't distribued twice.
// void Card::setCard(){
//     srand(time(0)); 
//     this->c = (rand() % 52) + 1;
// }

Card::Card() {
    // cout << "Card()" << endl; 
	this->c = -1;
}
// your code
// #endif