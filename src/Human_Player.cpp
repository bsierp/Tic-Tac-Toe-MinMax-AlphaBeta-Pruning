/**
 * @file Human_Player.cpp
 * @brief Plik zawiera definicje metod klasy Human_Player
 * @version 0.1
 * @date 2021-06-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "Human_Player.hh"
Human_Player::Human_Player(int s){
    if(s==1||s==-1)
        symbol=s;
    else
        throw invalid_symbol_error();
}
void Human_Player::move(Board & b, const Board_Manager & bm) const {
    int move_coordinates[2];
    std::cout<<"Który rząd?"<<std::endl;
    std::cin>>move_coordinates[0];
    std::cout<<"Która kolumna?"<<std::endl;
    std::cin>>move_coordinates[1];
    bm.move(b,this->get_symbol(),move_coordinates[0]-1,move_coordinates[1]-1);
}