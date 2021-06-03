#include "AI.hh"

void AI::move(Board & b,const Board_Manager & bm) const {
    int *move_coordinates=this->best_move(b);
    bm.move(b,this->get_symbol(),move_coordinates[0],move_coordinates[1]);
}
int AI::calculate(const Board & b) const{
    if(this->check_win(b,symbol))
        return 1;
    else if(this->check_win(b,-symbol))
        return -1;
    else
        return 0;
}
int AI::minimax(Board & b, int depth, int alpha, int beta, bool is_max) const{
    int score=this->calculate(b);
    if(score==1||score==-1)
        return score;
    if(this->is_over(b))
        return 0;
    if(depth==MAX_DEPTH){
        if(is_max)
            return 1;
        else
            return -1;
    }
    if(is_max){
        int best=_INF;
        for (int i = 0; i < b.get_board_size(); i++){
            for (int j = 0; j < b.get_board_size(); j++){
                if(b(i,j).get_symbol()==0){
                    b.set_element(this->get_symbol(),i,j);
                    best=std::max(best,minimax(b,depth+1,alpha,beta,!is_max));
                    b.set_element(0,i,j);
                    alpha=std::max(best,alpha);
                    if(beta<=alpha)
                        break;
                }
            }
        }
        return best;
    }
    else{
        int best=INF;
        for (int i = 0; i < b.get_board_size(); i++){
            for (int j = 0; j < b.get_board_size(); j++){
                if(b(i,j).get_symbol()==0){
                    b.set_element(-this->get_symbol(),i,j);
                    best=std::min(best,minimax(b,depth+1,alpha,beta,!is_max));
                    b.set_element(0,i,j);
                    beta=std::min(best,beta);
                    if(beta<=alpha)
                        break;
                }
            }
        }
        return best;
    }
}
int * AI::best_move(Board & b) const{
    int best_move=_INF;
    int *move = new int[2];
    for (int i = 0; i < b.get_board_size(); i++){
        for (int j = 0; j < b.get_board_size(); j++){
            if(b(i,j).get_symbol()==0){
                b.set_element(this->get_symbol(),i,j);
                int move_val=this->minimax(b,0,_INF,INF,false);
                b.set_element(0,i,j);
                if(move_val>best_move){
                    best_move=move_val;
                    move[0]=i;
                    move[1]=j;
                }
            }
        }
    }
    return move;
}