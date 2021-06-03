#ifndef BOARD_HH
#define BOARD_HH
/**
 * @file Board.hh
 * @brief Plik zawiera definicję klasy Board oraz deklarację jej metod
 * 
 */
#define MAX_BOARD_SIZE 8 //Maksymalny rozmiar planszy
#define MIN_BOARD_SIZE 3 //Minimalny rozmiar planszy
#include "Tile.hh"
#include <vector>
#include <stdexcept>
/**
 * @brief Klasa modeluje pojęcie planszy do gry w kółko i krzyżyk
 * 
 */
class Board{
    /**
     * @brief Rozmiar planszy
     * 
     */
    int board_size;
    /**
     * @brief Ilość znaków potrzebnych do wygranej
     * 
     */
    int row_win;
    /**
     * @brief Pola na planszy
     * 
     */
    std::vector<std::vector<Tile>> tiles;
public:
    Board();
    Board(int size, int win);
    const int & get_row_win() const {return this->row_win;};
    const int & get_board_size() const {return this->board_size;};
    const Tile & operator()(int r, int c) const;
    void set_element(int s, int r, int c) {this->tiles[r][c]=Tile(s);};
    std::string ret_board() const;
};


#endif