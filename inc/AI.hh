#ifndef AI_HH
#define AI_HH
#define INF 1000
#define _INF -1000
#define MAX_DEPTH 5
#include "Player.hh"
class AI:public Player, public Board_Manager{
public:
    AI(int s){symbol=s;};
    void move(Board & b,const Board_Manager & bm) const override;
    int calculate(const Board & b) const;
    int minimax(Board & b, int depth, int alpha, int beta, bool is_max) const;
    int * best_move(Board & b) const;
};
#endif
