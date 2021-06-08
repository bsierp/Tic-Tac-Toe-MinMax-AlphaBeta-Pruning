/**
 * @file Board_Manager.cpp
 * @brief Plik zawiera definicje metod klasy Board_Manager
 * 
 */
#include "Board_Manager.hh"

bool Board_Manager::check_row(const Board & b, int s) const{
    int to_win = s*b.get_row_win();
    int symbol_counter;
    for (int i = 0; i < b.get_board_size(); i++){
        symbol_counter=0;
        for (int j = 0; j < b.get_board_size(); j++){
            symbol_counter+=b(i,j).get_symbol();
            if(symbol_counter==to_win)
                return true;
            if(s!=b(i,j).get_symbol())
                symbol_counter=0;
        }
    }
    return false;
}
bool Board_Manager::check_collumn(const Board & b, int s) const{
    int to_win = s*b.get_row_win();
    int symbol_counter;
    for (int j = 0; j < b.get_board_size(); j++){
        symbol_counter=0;
        for (int i = 0; i < b.get_board_size(); i++){
            symbol_counter+=b(i,j).get_symbol();
            if(symbol_counter==to_win)
                return true;
            if(s!=b(i,j).get_symbol())
                symbol_counter=0;
        }
    }
    return false;
}
bool Board_Manager::check_diagonal(const Board & b, int s) const{
    int to_win=s*b.get_row_win();
    int symbol_counter;
    //Sprawdzenie czy znaki wygrywają w formacji lewy górny róg -> prawy dolny róg
    for (int i = 0; i <= b.get_board_size()-b.get_row_win(); i++){
        for (int j = 0; j <= b.get_board_size()-b.get_row_win(); j++){
            symbol_counter=0;
            for (int k = 0; k < b.get_row_win(); k++){
                symbol_counter+=b(i+k,j+k).get_symbol();
                if(symbol_counter==to_win)
                    return true;
            }
        }
    }
    //Sprawdzenie czy znaki wygrywają w formacji lewy dolny róg -> prawy górny róg
    for (int i = b.get_board_size(); i >= b.get_row_win(); i--){
        for (int j = 0; j <= b.get_board_size()-b.get_row_win(); j++){
            symbol_counter=0;
            for (int k = 0; k < b.get_row_win(); k++){
                symbol_counter+=b(i-k-1,j+k).get_symbol();
                if(symbol_counter==to_win)
                    return true;
            }
        }
    }
    return false;
}
bool Board_Manager::is_over(const Board & b) const {
    int is_empty=1;//Sprawdza, czy plansza jest pusta, będzie posiadać wartości 1 i -1 (true) oraz 0(false)
    for (int i = 0; i < b.get_board_size(); i++){
        for (int j = 0; j < b.get_board_size(); j++)
            is_empty*=b(i,j).get_symbol();
    }
    return bool(is_empty);
}
int Board_Manager::who_won(const Board & b) const {
    if (this->check_win(b,1))
        return 1;
    else if (this->check_win(b,-1))
        return -1;
    else if(this->is_over(b)&&!this->check_win(b,1)&&!this->check_win(b,-1))
        return 0;
    return 0;
}
void Board_Manager::move(Board & b, int s, int r, int c) const {
    if (this->is_valid(b,r,c))
        b.set_element(s,r,c);
    else
        throw invalid_move_error();
}
int Board_Manager::valid_moves_left(const Board & b) const {
    int moves_left;
    for (int i = 0; i < b.get_board_size(); i++){
        for (int j = 0; j < b.get_board_size(); j++){
            if(b(i,j).get_symbol()==0)
                moves_left++;
        }
    }
    return moves_left;
}