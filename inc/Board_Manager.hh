#ifndef BOARD_MANAGER_HH
#define BOARD_MANAGER_HH
#include "Board.hh"
#include "Exception.hh"
class Board_Manager{
protected:
    bool check_row(const Board & b, int s) const;
    bool check_collumn(const Board & b, int s) const;
    bool check_diagonal(const Board & b, int s) const;
    bool is_valid(const Board & b, int r, int c) const {return (r<b.get_board_size()&&c<b.get_board_size()&&b(r,c).get_symbol()==0);};
public:
    bool check_win(const Board & b, int s) const {return (this->check_row(b,s)||this->check_collumn(b,s)||this->check_diagonal(b,s));};
    bool is_over(const Board & b) const;
    int who_won(const Board & b) const;
    void move(Board & b, int s, int r, int c) const;
};
#endif