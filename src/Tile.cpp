/**
 * @file Tile.cpp
 * @brief Plik zawiera definicje metod klasy Tile
 * 
 */
#include "Tile.hh"

std::string Tile::ret_tile_symbol() const {
    if(this->symbol==X)
        return "X";
    else if (this->symbol==O)
        return "O";
    else
        return "-";
}