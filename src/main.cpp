/**
 * @file main.cpp
 * @brief Plik zawiera kod odpowiedzialny za przeprowadzenie gry
 */
#include "Human_Player.hh"
#include "AI.hh"
#include <memory>
#include <cstring>
int main(){
    std::vector<std::unique_ptr<Player>> players; 
    int temp1=_INF,temp2;
    bool done=false;
    std::cout<<"Witaj w grze kółko i krzyżyk!"<<std::endl<<"Zaczyna gracz z symbolem X"<<std::endl;
    while (temp1<0||temp1>2){
        std::cout<<"Wybierz ilość ludzkich graczy (0-2):";
        std::cin>>temp1;
        if(temp1<0||temp1>2||!std::cin.good()){
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cerr<<"Niepoprawna wartość"<<std::endl;
            temp1=-1;
        }        
    }
    try{
        if(temp1==2){
            players.push_back(std::unique_ptr<Player>(new Human_Player(1)));
            players.push_back(std::unique_ptr<Player>(new Human_Player(-1)));
        }
        else if(temp1==1){
            std::string ans="";
            while(!done){
                std::cout<<"Chcesz zacząć (t/n)?";
                std::cin>>ans;
                if(ans=="t"){
                    players.push_back(std::unique_ptr<Player>(new Human_Player(1)));
                    players.push_back(std::unique_ptr<Player>(new AI(-1)));
                    done=true;
                }
                else if(ans=="n"){
                    players.push_back(std::unique_ptr<Player>(new AI(1)));
                    players.push_back(std::unique_ptr<Player>(new Human_Player(-1)));
                    done=true;
                }
                else
                    std::cerr<<"Niepoprawna odpowiedź"<<std::endl;
            }
        }
        else{
            players.push_back(std::unique_ptr<Player>(new AI(1)));
            players.push_back(std::unique_ptr<Player>(new AI(-1)));
        }  
    }
    catch(const invalid_symbol_error & e){
        std::cerr<<e.what()<<std::endl;
        exit(-1);
    }
    done = false;
    while (!done){
        std::cout<<"Wpisz rozmiar planszy:";
        std::cin>>temp1;
        if(!std::cin.good()){
            done=false;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cerr<<"Niepoprawna wartość"<<std::endl;
            continue;
        }
        else
            done=true;
        std::cout<<"Wpisz ilość znaków potrzebną do wygranej:";
        std::cin>>temp2;
        if(!std::cin.good()){
            done=false;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cerr<<"Niepoprawna wartość"<<std::endl;
        }
        else
            done=true;
    }
    bool o_valid_move=true; //Gdyby wystąpił błąd podczas tury O, dzięki tej zmiennej pomijamy ruch X
    Board board(temp1,temp2);
    Board_Manager mng;
    mng.print_board(board);
    //Pętla z grą
    while (!mng.is_over(board)){
        try{
            if(o_valid_move){
                std::cout<<"X myśli..."<<std::endl;
                players[0]->move(board,mng);
                mng.print_board(board);
                if(mng.check_win(board,players[0]->get_symbol()))
                    break;
                if(mng.is_over(board))//Dla nieparzystych rozmiarów planszy
                    break;
            }
            o_valid_move=false;
            std::cout<<"O myśli..."<<std::endl;
            players[1]->move(board,mng);
            o_valid_move=true;
            mng.print_board(board);
            if(mng.check_win(board,players[1]->get_symbol()))
                break;
        }
        catch (const invalid_move_error & e){
            std::cerr<<e.what()<<std::endl;
            std::cout<<"Ponów ruch"<<std::endl;
        }
    }
    if(mng.who_won(board)==0)
        std::cout<<"Remis"<<std::endl;
    else
        std::cout<<"Wygrał:"<<Tile(mng.who_won(board)).ret_tile_symbol()<<std::endl;
    return 0;
}

