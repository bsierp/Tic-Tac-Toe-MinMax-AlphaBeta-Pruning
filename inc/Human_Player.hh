#ifndef HUMAN_PLAYER_HH
#define HUMAN_PLAYER_HH
#include "Player.hh"
#include <iostream>
class Human_Player:public Player{
public:
    Human_Player(int s){symbol=s;};
    void move(Board & b,const Board_Manager & bm) const override;
};


#endif