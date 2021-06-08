#ifndef AI_HH
#define AI_HH
/**
 * @file AI.hh
 * @brief Plik zawiera definicję klasy AI oraz deklarację jej metod
 * 
 */
#define INF 1000 //Najgorszy możliwy przypadek dla gracza min
#define _INF -1000 //Najgorszy możliwy przypadek dla gracza max
#define MAX_DEPTH 5 //Liczba ruchów przewidywanych w przód (przyspiesza działanie)
#include "Player.hh"
/**
 * @brief Klasa modeluje pojęcie sztucznej inteligenci, dziedziczy po klasie Player i Board_Manager
 * 
 */
class AI:public Player, public Board_Manager{
    /**
     * @brief Metoda zwraca wartość planszy w zależności od jej stanu (1-wygrana, 0-remis, -1-przegrana)
     * 
     * @param b - plansza do sprawdzenia
     * @return int - wartość planszy
     */
    int calculate(const Board & b) const;
    /**
     * @brief Metoda zwraca wartość ruchu w zależności od wartości planszy
     * 
     * Metoda symuluje grę podejmując jak najlepsze decyzje, minimalizujac ryzyko przegranej
     * oraz maksymalizując szansę na wygraną.
     * @param b - plansza do sprawdzenia
     * @param depth - głębokość algorytmu (numer przewidywanego ruchu)
     * @param alpha - parametr alfa, używany do odcięć alfa-beta
     * @param beta - parametr beta, używany do odcięć alfa-beta
     * @param is_max - flaga oznaczająca, czy chcemy przewidywać ruch gracza max, bądź gracza min
     * @return int - wartość ruchu
     */
    int minimax(Board & b, int depth, int alpha, int beta, bool is_max) const;
    /**
     * @brief Metoda zwraca współrzędne najlepszego ruchu
     * 
     * @param b - plansza do sprawdzenia
     * @return int* - wskaźnik na tablicę współrzędnych
     */
    int * best_move(Board & b) const;
public:
    /**
     * @brief Konstruktor klasy AI
     * Tworzy obiekt klasy AI o zadanym symbolu
     * @param s - wartość symbolu gracza
     * @throw invalid_symbol_error - w przypadku niewłaściwej wartości symbolu (innej niż 1/-1)
     */
    AI(int s);
    void move(Board & b,const Board_Manager & bm) const override;
};
#endif
