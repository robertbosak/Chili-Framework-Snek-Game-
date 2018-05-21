#ifndef snake_hpp
#define snake_hpp

#include "board.hpp"

class Snake
{
private:
    
    class Segment
    {
        
    public:
        
        void InitHead(const Location& loc);
        void InitBody(Color& c);
        void Follow(const Segment& next);
        void MoveBy(const Location& delta_loc);
        void Draw(Board& brd) const;
        
        inline const Location& GetLocation() const { return loc; }
        
    private:
        Location loc;
        Color color;
    };
    
public:
    Snake(const Location& loc );
    
    void MoveBy(const Location& delta_loc);
    Location GetNextHeadLocation(const Location& delta_loc) const;
    bool IsInTileExceptEnd(const Location& tile) const;
    bool IsInTile(const Location& tile) const;
    void Grow();
    void Draw(Board& brd) const;
    
private:
    //static constexpr Color headColor = Colors::Yellow;
    //static constexpr Color bodyColor = Colors::Green;
    static constexpr int nSegmentsMax = 100;
    Segment segments[nSegmentsMax];
    int nSegments = 1;
};

#endif /* snake_hpp */
