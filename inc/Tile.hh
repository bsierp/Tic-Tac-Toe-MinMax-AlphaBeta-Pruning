#ifndef TILE_HH
#define TILE_HH
#include <string>
class Tile{
    enum Tile_Val{
        X=1,
        O=-1,
        B=0
    };
    Tile_Val symbol;
    public:
    Tile(const int & s){symbol=static_cast<Tile_Val>(s);};
    std::string ret_tile_symbol() const;
    void set_tile(const int & s){this->symbol=static_cast<Tile_Val>(s);};
};
#endif