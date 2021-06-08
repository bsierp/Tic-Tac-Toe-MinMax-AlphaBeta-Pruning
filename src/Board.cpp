/**
 * @file Board.cpp
 * @brief Plik zawiera definicje metod klasy Board
 * 
 */
#include "Board.hh"

Board::Board(int size, int win){
    if (size>MAX_BOARD_SIZE)
        board_size=MAX_BOARD_SIZE;
    else if (size<MIN_BOARD_SIZE)
        board_size=MIN_BOARD_SIZE;
    else
        board_size=size;
    if (win>board_size)
        row_win=board_size;
    else if (win<MIN_BOARD_SIZE)
        row_win=MIN_BOARD_SIZE;
    else
        row_win=win;
    for (int i = 0; i < board_size; i++){//Inicjalizacja pustej planszy
        std::vector<Tile> tmp;
        for (int j = 0; j < board_size; j++)
            tmp.push_back(Tile(0));
        tiles.push_back(tmp);
    }
}
const Tile & Board::operator()(int r, int c) const{
    if(r<0||c<0)
        throw std::underflow_error("Wprowadzono ujemny indeks");
    else if(r>this->get_board_size()-1||c>this->get_board_size()-1)
        throw std::overflow_error("Indeks planszy większy niż jej rozmiar");
    else
        return this->tiles[r][c];
}
std::string Board::ret_board() const {
    std::string board="   ";
    for (int i = 0; i < this->get_board_size(); i++){
        board+=std::to_string(i+1);
        board+=".";
    }
    board+="\n";
    for (int i = 0; i < this->get_board_size(); i++){
        board+=std::to_string(1+i);
        board+=". ";
        for (int j = 0; j < this->get_board_size(); j++){
            board+=(*this)(i,j).ret_tile_symbol();
            board+="|";
            if(j==this->get_board_size()-1)
            board+="\n";
        }
    }
    return board;
}
