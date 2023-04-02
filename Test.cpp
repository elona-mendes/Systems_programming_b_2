#include "doctest.h"
#include <stdexcept>
#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

TEST_CASE("Init player (1)") {
    Player p("Alice");

    CHECK(p.stacksize() == 26);
    CHECK(p.cardesTaken() == 0);
    CHECK(p.getSumpnt() == 0);
    CHECK(p.getName().compare("Alice"));
}

TEST_CASE("Test one Turn (2)"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    game.playTurn();

    if(p1.stacksize() == 25){
        if(p1.cardesTaken() == 2){
            CHECK(p2.stacksize() == 25);
            CHECK(p2.cardesTaken() == 0);
        }
        else{
            CHECK(p1.cardesTaken() == 0);
            CHECK(p2.stacksize() == 25);
            CHECK(p2.cardesTaken() == 2);
        }
    }
    else{
        CHECK(p1.stacksize() == 23);
        CHECK(p2.stacksize() == 23);
        if(p1.cardesTaken() == 6){
            CHECK(p2.cardesTaken() == 0);
        }
        else{
            CHECK(p2.cardesTaken() == 0);
            CHECK(p2.cardesTaken() == 6);
        }
    }
}

TEST_CASE("Test stacks after all game (3)"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    game.playAll();
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK((p2.cardesTaken()+p1.cardesTaken()) == 52);
}

TEST_CASE("Test stacks after some turn (4)"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    for (int i=0;i<5;i++) {
        game.playTurn();
    }
    CHECK(p1.stacksize() <= 21);
    CHECK(p2.stacksize() == p1.stacksize());
    CHECK((p2.cardesTaken()+p1.cardesTaken()) >= 10);
}

TEST_CASE("Test play one turn after empty stack - Error (5)"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    //if its stop, the two players cant play another turn because they havn't cards.
    for (int i=0;i<10;i++) {
        game.playTurn();
    } 
    // while (p1.stacksize()>0) {
    //     game.playTurn();
    // }
    CHECK_THROWS(game.playTurn());  // check that some exception is thrown
}

TEST_CASE("Play two games at same time (6)"){
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Anna");
    Player p4("Dani");

    Game game1(p1,p2);
    Game game2(p3,p4);
    game1.playTurn();
    game2.playTurn();
    CHECK(p1.stacksize() < 25); 
    CHECK(p2.stacksize() < 25); 
    CHECK(p3.stacksize() < 25); 
    CHECK(p4.stacksize() < 25); 
}

TEST_CASE("Print last turn after one turn (7)"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    game.playTurn();
    //== 0 mean print succesfuly
    CHECK(game.printLastTurn() == 0);
}

TEST_CASE("Try to print last turn before play a turn - Error (8)"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    //cant print last turn because havn't turns
    CHECK_THROWS(game.printLastTurn());
}

TEST_CASE("Try to printLog after 2 turn (9)"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    game.playTurn();
    game.playTurn();
    //cant print last turn because havn't last turn
    CHECK(game.printLog() == 0);
}

TEST_CASE("Try to printLog before play a turn - Error (10)"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    //cant print log because havn't last turns
    CHECK_THROWS(game.printLog());
}

TEST_CASE("Print the winner at the end of the game (11)"){

    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    game.playAll();

    CHECK( game.printWiner() == 0);
}

TEST_CASE("Try to printWiner before the end of the game - Error (12)"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    for (int i=0;i<5;i++) {
        game.playTurn();
    } 

    if(p1.stacksize()!=0){
        //cant print winner because the game not end 
        CHECK_THROWS(game.printWiner());
    }
}

TEST_CASE("Try to printWiner before the beginning of thr game - Error (13)"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    CHECK_THROWS(game.printWiner());
}

TEST_CASE("player try to play in 2 games at same time - Error (14)"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    Game game1(p1,p2);
    //the players cant play if there are in two games.
    CHECK_THROWS(game.playTurn());
}

TEST_CASE("check card without aquality (15)"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    game.playTurn();
    //when game make a turn the player take a card, and after that the last card that was played are in  player.card()
    if (p1.cardesTaken() < 6 && p2.cardesTaken() < 6){
        if(p1.card() > p2.card()){
        CHECK(p1.cardesTaken() == 2);
        CHECK(p2.cardesTaken() == 0);
        }
        else{
            CHECK(p1.cardesTaken() == 0);
            CHECK(p2.cardesTaken() == 2);
        }
    }
}

TEST_CASE("check set card (16)"){
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    p1.setCrd(6);
    p2.setCrd(6);
    CHECK(p2.card() == p1.card());

    p2.setCrd(9);
    CHECK(p2.card() > p1.card());

    p1.setCrd(11);
    CHECK(p2.card() < p1.card());
}

TEST_CASE("check set card with duplicated values (17)"){
    //Each number has 4 options to be and no more, we will check that an error is 
    //issued for times.

    Player p1("Alice");
    Player p2("Bob");

    p1.setCrd(6);
    p1.setCrd(6);
    p1.setCrd(6);
    p1.setCrd(6);

    CHECK_THROWS(p1.setCrd(6));
}

TEST_CASE("check set card with errors values (18)"){

    Player p1("Alice");

    CHECK_THROWS(p1.setCrd(0));
    CHECK_THROWS(p1.setCrd(14));
    CHECK_THROWS(p1.setCrd(-2));
}

TEST_CASE("Init player without name, default player (19)"){
    Player p1;

    CHECK(p1.getName().compare("None"));
    CHECK(p1.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p1.getSumpnt() == 0);
}

TEST_CASE("Init game without players, default players (20)"){
    Game game;
    CHECK(game.getp1().getName().compare("None1"));
    CHECK(game.getp2().getName().compare("None2"));
    CHECK(game.getp1().stacksize() == 26);
    CHECK(game.getp1().cardesTaken() == 0);
    CHECK(game.getp1().getSumpnt() == 0);
}
