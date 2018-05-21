#include "board.hpp"
#include <assert.h>

Board::Board(Graphics& graphics)
:
gfx(graphics)
{
    
}

void Board::DrawCell(const Location &loc, Color c)
{
    assert(loc.x + boardOffsetX >= boardOffsetX);
    assert(loc.x + boardOffsetX < (width * dimension) + boardOffsetX);
    assert(loc.y + boardOffsetY >= boardOffsetY);
    assert(loc.y + boardOffsetY < (height * dimension) + boardOffsetY);
    
    
    gfx.drawRectDim(boardOffsetX + (loc.x * dimension), boardOffsetY + (loc.y * dimension), dimension - 1, dimension - 1, c);
}

bool Board::IsInsideBoard(const Location &loc) const
{
    return loc.x >= 1 && loc.x < width - 1 && loc.y >= 1 && loc.y < height - 1;
}

void Board::DrawBoarder(Graphics &gfx)
{
    for(int j = boardOffsetY; j < (height * dimension) + boardOffsetY; ++j)
    {
        for(int i = boardOffsetX; i < (width * dimension) + boardOffsetX; ++i)
        {
            if((i > boardOffsetX && i <= boardOffsetX + dimension) || (i < boardOffsetX + (width * dimension) && i > boardOffsetX + (width * dimension - dimension)))
                gfx.PutPixel(i, j, 0, 0, 200);
            else if((j > boardOffsetY && j <= boardOffsetY + dimension) || (j < boardOffsetY + (height * dimension) && j > boardOffsetY + (height * dimension - dimension)))
                gfx.PutPixel(i, j, 0, 0, 200);
        }
    }
}



