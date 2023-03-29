#include <iostream>
#include <stdexcept>
#include "card.hpp"

// // some_header_file.h
#ifndef Player_H
#define Player_H

using namespace std;

namespace ariel {
    class Player{
        private:    // Not required. All is private by default.
            string name;
            int stksize;
            int tken;
            int sumpoint;
            int crd;

        public:
            // methods defined inline:
            string getName();
            int getSumpnt();
            int card();
            void setCrd(int num);

            // methods defined in the CPP file:
            void setX(string);
            void setY(string); 

            std::string to_string();

            // // Constructors:
            Player() ;
            //{
            //     std::cout << "Player()" << std::endl; 
            //     name = "None";
            //     stksize = 26;
            //     tken = 0;
            //     sumpoint = 0;
            //     crd = 1;
            // }
            Player(string n) ;
            // { 
            //     std::cout << "Player(string)" << std::endl; 
            //     name =  n; 
            //     stksize = 26;
            //     tken = 0;
            //     sumpoint = 0;
            //     // crd = Card();
            // }

            int stacksize();

            int cardesTaken();
    };
}

// // your code
#endif