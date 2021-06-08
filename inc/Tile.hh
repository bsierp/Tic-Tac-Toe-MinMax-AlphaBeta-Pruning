#ifndef TILE_HH
#define TILE_HH
/**
 * @file Tile.hh
 * @brief Plik zawwiera definicje klasy Tile oraz deklaracje jej metod
 * 
 */
#include <string>
/**
 * @brief Klasa Tile, modelująca pojęcie pojedynczego pola na planszy
 * 
 */
class Tile{
    /**
     * @brief Wyliczeniowy typ, odpowiadający poszczególnym stanom pola (B dla pustego pola)
     * 
     */
    enum Tile_Val{
        X=1,
        O=-1,
        B=0
    };
    /**
     * @brief Zmienna przechowująca symbol znajdujący się w polu
     * 
     */
    Tile_Val symbol;
    public:
    /**
     * @brief Konstruktor klasy Tile
     * 
     * Tworzy obiekt klasy Tile o zadanym symbolu
     * @param s - symbol w polu (wartość w int jest rzutowana na wartość symbolu)
     */
    Tile(const int & s){symbol=static_cast<Tile_Val>(s);};
    /**
     * @brief Zwraca symbol znajdujący się w polu w postaci ciągu znakowego
     * 
     * @return std::string - symbol znajdujący się w polu w postaci tekstowej
     */
    std::string ret_tile_symbol() const;
    /**
     * @brief Zmienia symbol przechowywany w polu
     * 
     * @param s - nowy symbol
     */
    void set_tile(const int & s){this->symbol=static_cast<Tile_Val>(s);};
    /**
     * @brief Zwraca wartość symbolu
     * 
     * @return const Tile_Val& - wartość symbolu
     */
    const Tile_Val & get_symbol() const {return this->symbol;};
};
#endif