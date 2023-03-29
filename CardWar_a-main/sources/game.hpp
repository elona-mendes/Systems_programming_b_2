#include <iostream>
#include <stdexcept>
#include "player.hpp" 

using namespace std;

namespace ariel {
    class Game{
        private:    // Not required. All is private by default.
            Player p1;
            Player p2;

        public:
            // methods defined inline:
            Player getp1();
            Player getp2();

            std::string to_string();

            // // Constructors:
            Game();
            
            Game(Player pl1, Player pl2);

            int printLastTurn();

            void playTurn();

            void playAll();

            int printWiner();

            int printLog();

            int printStats();

    };
}