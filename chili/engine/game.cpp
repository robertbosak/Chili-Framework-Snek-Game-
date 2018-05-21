#include "game.h"
#include "spriteCodex.hpp"

Game::Game(MainWindow& window)
:
wnd(window),
gfx(Graphics()),
brd(gfx),
rng(std::random_device()()),
snek(Snake({2, 2})),
goal(Goal(rng, brd, snek))
{
}

Game::~Game()
{
}

void Game::go()
{
	while(!glfwWindowShouldClose(wnd.getWindow()))
	{
		wnd.processEvents();
		updateModel();
		
		gfx.beginFrame();
		composeFrame();
        gfx.endFrame();
		wnd.show();
	}
}

void Game::updateModel()
{
    if(!gameIsOver)
    {
        if(wnd.kbd.isPressed(wnd.getWindow(), GLFW_KEY_UP))
        {
            delta_loc = {0, -1};
        }
        else if(wnd.kbd.isPressed(wnd.getWindow(), GLFW_KEY_DOWN))
        {
            delta_loc = {0, 1};
        }
        else if(wnd.kbd.isPressed(wnd.getWindow(), GLFW_KEY_LEFT))
        {
            delta_loc = {-1, 0};
        }
        else if(wnd.kbd.isPressed(wnd.getWindow(), GLFW_KEY_RIGHT))
        {
            delta_loc = {1, 0};
        }
        ++snekMoveCounter;
        if(snekMoveCounter > snekMovePeriod)
        {
            snekMoveCounter = 0;
            
            const Location next = snek.GetNextHeadLocation(delta_loc);
            
            if(!brd.IsInsideBoard(next) || snek.IsInTileExceptEnd(next))
                gameIsOver = true;
            else
            {
                bool eating = (next == goal.GetLocation());
                if(eating)
                {
                    snek.Grow();
                    snekMovePeriod--;
                    
                    if(snekMovePeriod < 5)
                        snekMovePeriod = 20;
                    
                }
                
                snek.MoveBy(delta_loc);
                if(eating)
                    goal.Respawn(rng, brd, snek);
            }
        }
    }
}

void Game::composeFrame()
{
    if(!start)
    {
        SpriteCodex::DrawTitle(((brd.GetGridWidth()/2) * 5) + Board::boardOffsetX, ((brd.GetGridHeight()/2) * 5) + Board::boardOffsetY, gfx);

        if(wnd.kbd.isPressed(wnd.getWindow(), GLFW_KEY_ENTER))
            start = true;
    }
    if(start)
    {
        brd.DrawBoarder(gfx);
        snek.Draw(brd);
        goal.Draw(brd);
        
        if(gameIsOver)
            SpriteCodex::DrawGameOver(Board::boardOffsetX + ((brd.GetGridWidth()/2) * 7), Board::boardOffsetY + ((brd.GetGridHeight() / 2) * 7), gfx);
    }

}

//..........USER Methods.................................................//


//......................................................................//




















