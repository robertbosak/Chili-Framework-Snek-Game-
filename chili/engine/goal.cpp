#include "goal.hpp"

static constexpr Color c = Colors::Red;

Goal::Goal(std::mt19937& rng, const Board& brd, const Snake& snake)
{
    Respawn(rng, brd, snake);
}

void Goal::Respawn(std::mt19937& rng, const Board& brd, const Snake& snake)
{
    std::uniform_int_distribution<int> xDist(2, brd.GetGridWidth() - brd.GetCellSize());
    std::uniform_int_distribution<int> yDist(2, brd.GetGridHeight() - brd.GetCellSize());
    
    Location newLoc;
    do
    {
        newLoc = {xDist(rng), yDist(rng)};
    } while(snake.IsInTile(newLoc));
    
    loc = newLoc;
}

void Goal::Draw(Board& brd) const
{
    brd.DrawCell(loc, c);
}
