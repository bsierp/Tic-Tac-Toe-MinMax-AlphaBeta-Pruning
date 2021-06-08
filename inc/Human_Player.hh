#ifndef HUMAN_PLAYER_HH
#define HUMAN_PLAYER_HH
/**
 * @file Human_Player.hh
 * @brief Plik zawwiera definicje klasy Human_Player oraz deklaracje jej metod
 * 
 */
#include "Player.hh"
/**
 * @brief Klasa modeluje pojęcie ludzkiego gracza, dziedziczy po abstrakcyjnej klasie Player
 * 
 */
class Human_Player:public Player{
public:
    /**
     * @brief Konstruktor klasy Human_Player
     * Tworzy obiekt klasy Human_Player o zadanym symbolu
     * @param s - wartość symbolu gracza
     * @throw invalid_symbol_error - w przypadku niewłaściwej wartości symbolu (innej niż 1/-1)
     */
    Human_Player(int s);
    void move(Board & b,const Board_Manager & bm) const override;
};


#endif