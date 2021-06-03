#ifndef PLAYER_HH
#define PLAYER_HH
#include "Board_Manager.hh"

class Player{
protected:
    int symbol;
public:
    virtual void move(Board & b,const Board_Manager & bm) const=0;
    const int & get_symbol() const {return this->symbol;};
};
#endif