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
    //bool check_row(Tile symbol) const;
    //bool check_collumn(Tile symbol) const;
    //bool check_diagonal(Tile symbol) const;
public:
    Board(int s, int w);
    //bool check_win(Tile symbol) const;
    //bool is_over() const;
    const int & get_row_win() const;
    const int & get_board_size() const;
    const Tile & operator()(int r,int c) const;
    void print_board() const;
};


#endif