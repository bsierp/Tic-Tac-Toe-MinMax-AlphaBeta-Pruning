#include "Human_Player.hh"
#include "AI.hh"
int main(){
    Board board(8,8);
    Board_Manager mng;
    Human_Player me(1);
    AI bot(-1);
    while (!mng.is_over(board)){
        std::cout<<"Wpisz koordynaty po spacji:";
        me.move(board,mng);
        std::cout<<std::endl<<board.ret_board()<<std::endl;
        if(mng.check_win(board, 1)||mng.check_win(board,-1))
            break;
        bot.move(board,mng);
        std::cout<<board.ret_board()<<std::endl;
    }
    std::cout<<"Wygrał:"<<Tile(mng.who_won(board)).ret_tile_symbol()<<std::endl;
    return 0;
}

