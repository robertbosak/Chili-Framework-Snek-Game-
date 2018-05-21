#ifndef board_hpp
#define board_hpp

#include "graphics.h"
#include "location.h"

class Board
{
public:
    Board(Graphics& graphics);
    
    void DrawBoarder(Graphics& gfx);
    void DrawCell(const Location& loc, Color c);
    
    inline int GetGridWidth() const { return width; }
    inline int GetGridHeight() const { return height; }
    inline int GetCellSize() const { return dimension; }
    
    bool IsInsideBoard(const Location& loc) const;
    
private:
    static constexpr int dimension = 10;
    static constexpr int width = 40;
    static constexpr int height = 40;
    
    Graphics& gfx;
    
};

#endif /* board_hpp */
