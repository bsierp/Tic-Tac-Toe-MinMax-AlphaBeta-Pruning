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
    /**
     * @brief Konstruktor klasy Board
     * Tworzy planszę o zadanym rozmiarze i ilości znaków do wygrania
     * @param size - rozmiar planszy
     * @param win - ilość znaków potrzebna do wygranej
     */
    Board(int size, int win);
    /**
     * @brief Zwraca ilość znaków potrzebnych do wygranej
     * 
     * @return const int& - ilość znaków potrzebnych do wygranej
     */
    const int & get_row_win() const {return this->row_win;};
    /**
     * @brief Zwraca rozmiar planszy (ilość znaków w rzędzie/kolumnie)
     * 
     * @return const int& - rozmiar planszy
     */
    const int & get_board_size() const {return this->board_size;};
    /**
     * @brief Zwraca wartość symbolu z konkretnego miejsca na planszy
     * 
     * @param r - rząd symbolu
     * @param c - kolumna symbolu
     * @return const Tile& - wartość symbolu
     */
    const Tile & operator()(int r, int c) const;
    /**
     * @brief Ustawia znak na zadanym miejscu na planszy
     * 
     * @param s - wartość symbolu
     * @param r - rząd
     * @param c - kolumna
     */
    void set_element(int s, int r, int c) {this->tiles[r][c]=Tile(s);};
    /**
     * @brief Zwraca planszę w postaci ciągu znakowego
     * 
     * @return std::string - plansza w postaci tekstowej
     */
    std::string ret_board() const;
};


#endif