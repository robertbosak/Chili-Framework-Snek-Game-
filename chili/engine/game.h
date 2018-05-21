#ifndef GAME_H
#define GAME_H

#include <random>

#include "window.h"
#include "graphics.h"
#include "board.hpp"
#include "snake.hpp"
#include "goal.hpp"

class Game
{
public:
    Game(MainWindow& window);
    ~Game();

    void go();

    void updateModel();
    void composeFrame();
    
    //...........USER METHODS............................//
    bool gameIsOver = false;
    
    //...................................................//

private:
    MainWindow& wnd;
    Graphics gfx;

    //...........USER VARIABLES.........................//
    Board brd;
    std::mt19937 rng;
    
    int snekMovePeriod = 20;
    int snekMoveCounter = 0;
    
    Location delta_loc = {1, 0};
    Snake snek;
    Goal goal; //add after board and snake so goal knows about them to initialize goal
    
    bool start = false;
    //.................................................//
		
};

#endif
