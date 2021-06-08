/**
 * @file AI.cpp
 * @brief Plik zawiera definicje metod klasy AI
 * 
 */
#include "AI.hh"
AI::AI(int s){
    if(s==1||s==-1)
        symbol=s;
    else
        throw invalid_symbol_error();
}
void AI::move(Board & b,const Board_Manager & bm) const {
    int *move_coordinates=this->best_move(b);
    bm.move(b,this->get_symbol(),move_coordinates[0],move_coordinates[1]);
    delete move_coordinates;
}
int AI::calculate(const Board & b) const{
    if(this->check_win(b,symbol))//Wygrana
        return 1;
    else if(this->check_win(b,-symbol))//Przegrana
        return -1;
    else                    //Remis
        return 0;
}
int AI::minimax(Board & b, int depth, int alpha, int beta, bool is_max) const{
    int score=(MAX_DEPTH-depth)*this->calculate(b);
    //W przypadku wygranej bądź przegranej
    if(this->check_win(b,this->get_symbol()))
        return score;
    if(this->check_win(b,-this->get_symbol()))
        return score;
    if(this->is_over(b))//W przypadku zakończonej gry
        return 0;
    //Gdy osiągniemy maksymalną liczbę ruchów, zwracamy wartości najlepsze dla poszczególnych graczy max/min
    if(depth==MAX_DEPTH){
        //return this->calculate(b);
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
                    best=std::max(best,minimax(b,depth+1,alpha,beta,!is_max)); //Przewidujemy ruch gracza min
                    b.set_element(0,i,j);
                    alpha=std::max(best,alpha); 
                    if(beta<=alpha)//Przerywamy przeszukiwanie
                        return best;
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
                    best=std::min(best,minimax(b,depth+1,alpha,beta,!is_max)); //Przewidujemy ruch gracza max
                    b.set_element(0,i,j);
                    beta=std::min(best,beta);
                    if(beta<=alpha)//Przerywamy przeszukiwanie
                        return best;
                }
            }
        }
        return best;
    }
}
int * AI::best_move(Board & b) const{
    int best_move=_INF;//Ustawiamy najgorszy przypadek
    int move_val;//Wartość ruchu
    int *move = new int[2];
    for (int i = 0; i < b.get_board_size(); i++){
        for (int j = 0; j < b.get_board_size(); j++){
            if(b(i,j).get_symbol()==0){
                b.set_element(this->get_symbol(),i,j);
                move_val=this->minimax(b,0,_INF,INF,false);
                b.set_element(0,i,j);
                if(move_val>best_move){//Najlepszy ruch
                    best_move=move_val;
                    move[0]=i;
                    move[1]=j;
                }
            }
        }
    }
    return move;
}