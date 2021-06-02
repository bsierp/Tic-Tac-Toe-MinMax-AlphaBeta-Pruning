#ifndef BOARD_MANAGER_HH
#define BOARD_MANAGER_HH
#include "Board.hh"
class Board_Manager{
    bool check_row(const Board & b, int s) const;
    bool check_collumn(const Board & b, int s) const;
    bool check_diagonal(const Board & b, int s) const;
    bool is_valid(const Board & b, int x, int y) const;
public:
    Board_Manager();
    bool check_win(const Board & b, int s) const;
    bool is_over(const Board & b) const;
    int who_won(const Board & b) const;
    void move(const Board & b, int s, int x, int y) const;
};
#endif