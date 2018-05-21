#include "board.hpp"
#include <assert.h>

Board::Board(Graphics& graphics)
:
gfx(graphics)
{
    
}

void Board::DrawCell(const Location &loc, Color c)
{
    assert(loc.x >= 0);
    assert(loc.x < width);
    assert(loc.y >= 0);
    assert(loc.y < height);
    
    
    gfx.drawRectDim(loc.x * dimension, loc.y * dimension, dimension - 1, dimension - 1, c);
}

bool Board::IsInsideBoard(const Location &loc) const
{
    return loc.x >= 1 && loc.x < width - 1 && loc.y >= 1 && loc.y < height - 1;
}

void Board::DrawBoarder(Graphics &gfx)
{
    for(int j = 0; j < height * dimension; ++j)
    {
        for(int i = 0; i < width * dimension; ++i)
        {
            if(i <= dimension || i > width * dimension - dimension)
                gfx.PutPixel(i, j, 0, 0, 200);
            else if(j <= dimension || j > height * dimension - dimension)
                gfx.PutPixel(i, j, 0, 0, 200);
        }
    }
}



