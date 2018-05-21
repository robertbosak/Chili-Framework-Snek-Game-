#ifndef goal_hpp
#define goal_hpp

#include <random>

#include "snake.hpp"
#include "board.hpp"

class Goal
{
public:
    Goal(std::mt19937& rng, const Board& brd, const Snake& snake);
    void Respawn(std::mt19937& rng, const Board& brd, const Snake& snake);
    void Draw(Board& brd) const;
    
    inline const Location& GetLocation() const { return loc; }
    
private:
    //static constexpr Color c = Colors::Red;
    Location loc;
};

#endif /* goal_hpp */
