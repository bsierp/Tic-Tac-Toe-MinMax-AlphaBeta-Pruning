#include "Human_Player.hh"

void Human_Player::move(Board & b, const Board_Manager & bm) const {
    int move_coordinates[2];
    std::cin>>move_coordinates[0]>>move_coordinates[1];
    bm.move(b,this->get_symbol(),move_coordinates[0],move_coordinates[1]);
}