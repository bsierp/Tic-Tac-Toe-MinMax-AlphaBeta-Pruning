#ifndef PLAYER_HH
#define PLAYER_HH
/**
 * @file Player.hh
 * @brief Plik zawwiera definicje abstrakcyjnej klasy Player oraz deklaracje jej metod
 * 
 */
#include "Board_Manager.hh"
/**
 * @brief Abstrakcyjna klasa Player, modeluje pojęcie gracza 
 * 
 */
class Player{
protected:
    /**
     * @brief Zmienna przechowująca wartość symbolu gracza
     * 
     */
    int symbol;
public:
    /**
     * @brief Metoda wykonująca ruch na planszy
     * 
     * @param b - plansza, na której będzie wykonywany ruch
     * @param bm - menedżer, za pomocą którego wykona się ruch na planszy
     */
    virtual void move(Board & b,const Board_Manager & bm) const=0;
    /**
     * @brief Zwraca wartość symbolu gracza
     * 
     * @return const int& - wartość symbolu gracza
     */
    const int & get_symbol() const {return this->symbol;};
};
#endif