#ifndef BOARD_MANAGER_HH
#define BOARD_MANAGER_HH
/**
 * @file Board_Manager.hh
 * @brief Plik zawiera definicję klasy Board_Manager oraz deklarację jej metod
 * 
 */
#include "Board.hh"
#include "Exception.hh"
#include <iostream>
/**
 * @brief Klasa modeluje pojęcie obiektu zarządzającego planszą do gry
 * 
 */
class Board_Manager{
protected:
    /**
     * @brief Metoda sprawdza czy nastąpiła wygrana w rzędzie dla zadanego symbolu
     * 
     * @param b - plansza do sprawdzenia
     * @param s - symbol dla którego sprawdzana jest wygrana
     * @return true - dla znalezienia ilości symboli s w rzędzie odpowiadającej wartości wymaganych znaków do wygranej
     * @return false - w przeciwnym wypadku
     */
    bool check_row(const Board & b, int s) const;
    /**
     * @brief Metoda sprawdza czy nastąpiła wygrana w kolumnach dla zadanego symbolu
     * 
     * @param b - plansza do sprawdzenia
     * @param s - symbol dla którego sprawdzana jest wygrana
     * @return true - dla znalezienia ilości symboli s w kolumnie odpowiadającej wartości wymaganych znaków do wygranej
     * @return false - w przeciwnym wypadku
     */
    bool check_collumn(const Board & b, int s) const;
    /**
     * @brief Metoda sprawdza czy nastąpiła wygrana po przekątnej dla zadanego symbolu
     * 
     * @param b - plansza do sprawdzenia
     * @param s - symbol dla którego sprawdzana jest wygrana
     * @return true - dla znalezienia ilości symboli s na przekątnej odpowiadającej wartości wymaganych znaków do wygranej
     * @return false - w przeciwnym wypadku
     */
    bool check_diagonal(const Board & b, int s) const;
    /**
     * @brief Metoda sprawdza, czy ruch może zostać wykonany
     * 
     * @param b - plansza do sprawdzenia
     * @param r - rząd
     * @param c - kolumna
     * @return true - dla właściwie podanych współrzędnych ruchu
     * @return false - w przeciwnym wypadku
     */
    bool is_valid(const Board & b, int r, int c) const {return (r<b.get_board_size()&&c<b.get_board_size()&&b(r,c).get_symbol()==0);};
    /**
     * @brief Metoda zwraca ilość dostępnych ruchów
     * 
     * @param b - plansza do sprawdzenia
     * @return int - ilość dostępnych ruchów
     */
    int valid_moves_left(const Board & b) const;
public:
    /**
     * @brief Metoda sprawdza czy nastąpiła wygrana dla danego symbolu
     * 
     * @param b - plansza do sprawdzenia
     * @param s - symbol dla którego sprawdzana jest wygrana
     * @return true - jeśli nastąpiła wygrana w rzędzie, kolumnie lub po przekątnej
     * @return false - w przeciwnym wypadku
     */
    bool check_win(const Board & b, int s) const {return (this->check_row(b,s)||this->check_collumn(b,s)||this->check_diagonal(b,s));};
    /**
     * @brief Metoda sprawdza czy gra jest skończona
     * 
     * @param b - plansza do sprawdzenia
     * @return true - gdy nie ma już ruchów
     * @return false - w przeciwnym wypadku
     */
    bool is_over(const Board & b) const;
    /**
     * @brief Metoda zwraca wartość zwycięskiego symbolu na planszy
     * 
     * @param b - plansza do sprawdzenia
     * @return int - wartość symbolu
     */
    int who_won(const Board & b) const;
    /**
     * @brief Metoda wykonuje ruch po planszy
     * 
     * @param b - plansza do wykonania ruchu
     * @param s - symbol ustawiany na planszy
     * @param r - rząd
     * @param c - kolumna
     * @throw invalid_move_error - gdy na wskazane pole jest niewłaściwy
     */
    void move(Board & b, int s, int r, int c) const;
    /**
     * @brief Metoda wyświetla planszę
     * 
     * @param b - plansza do wyświetlenia
     */
    void print_board(const Board & b) const {std::cout<<'\n'<<b.ret_board()<<'\n';};
};
#endif