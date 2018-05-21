#include "snake.hpp"
#include <math.h>
#include <assert.h>

static constexpr Color headColor = Colors::Yellow;
static constexpr Color bodyColor = Colors::Green;

Snake::Snake(const Location &loc)
{
    segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location &delta_loc)
{
    for(int i = nSegments - 1; i > 0; --i)
    {
        segments[i].Follow(segments[i - 1]);
    }
    segments[0].MoveBy(delta_loc);
}

void Snake::Grow()
{
    if(nSegments < nSegmentsMax)
    {
        Color c;
        
        if(nSegments % 2 == 0 )
            c = Colors::Cyan;
        else if(nSegments % 2 == 1)
            c = bodyColor;
        
        segments[nSegments].InitBody(c);
        ++nSegments;
    }
}

void Snake::Draw(Board &brd) const
{
    for(int i = 0; i < nSegments; ++i)
    {
        segments[i].Draw(brd);
    }
}

Location Snake::GetNextHeadLocation(const Location &delta_loc) const
{
    Location l(segments[0].GetLocation());
    l.Add(delta_loc);
    return l;
}

bool Snake::IsInTileExceptEnd(const Location& tile) const
{
    for(int i = 0; i < nSegments - 1; ++i)
    {
        if(segments[i].GetLocation() == tile)
            return true;
    }
    return false;
}

bool Snake::IsInTile(const Location& tile) const
{
    for(int i = 0; i < nSegments; ++i)
    {
        if(segments[i].GetLocation() == tile)
            return true;
    }
    return false;
}


void Snake::Segment::InitHead(const Location& in_loc)
{
    loc = in_loc;
    color = headColor;
}

void Snake::Segment::InitBody(Color& c)
{
    color = c;
}

void Snake::Segment::Follow(const Snake::Segment& next)
{
    loc = next.loc;
}

void Snake::Segment::MoveBy(const Location& delta_loc)
{
    assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
    loc.Add(delta_loc);
}

void Snake::Segment::Draw(Board& brd) const
{
    brd.DrawCell(loc, color);
}
