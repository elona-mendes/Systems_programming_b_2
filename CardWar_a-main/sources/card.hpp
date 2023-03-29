#include <stdexcept>
#include <cstdlib>
#include <iostream>

using namespace std;

#ifndef CARD_H
#define CARD_H

namespace ariel {
    class Card{

        private:
            int c;

        public:
            // methods defined inline
            // need to be change to numbers that cant randomly by choosen twise:
            int getCard();

            // void setCard();

            Card();
    };

}
// your code
#endif