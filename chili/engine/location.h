#ifndef location_h
#define location_h

class Location
{
public:
    bool operator==(const Location& rhs) const
    {
        return x == rhs.x && y == rhs.y;
        
    }
    void Add(const Location& value)
    {
        x += value.x;
        y += value.y;
    }
    int x;
    int y;
};

#endif /* location_h */
