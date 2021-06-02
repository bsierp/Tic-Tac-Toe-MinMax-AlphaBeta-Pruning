#ifndef BOARD_HH
#define BOARD_HH
#define MAX_BOARD_SIZE 10
#define MIN_BOARD_SIZE 3
#include "Tile.hh"
#include <vector>
class Board{
    int board_size;
    int row_win;
    std::vector<std::vector<Tile>> tiles;
public:
    Board();
    Board(int size, int win);
    void board_init();
    const int & get_row_win() const;
    const int & get_board_size() const;
    const Tile & operator()(int r, int c) const;
    void set_element(int s, int x, int y);
    void print_board() const;
};


#endif