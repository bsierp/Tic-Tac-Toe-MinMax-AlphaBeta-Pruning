/**
 * @file Exception.hh
 * @brief Plik zawiera definicje wyjątków
 * 
 */
#include<stdexcept>
/**
 * @brief Definicja prostego wyjątku niewłaściwego ruchu
 * 
 */
struct invalid_move_error : public std::exception
{
    /**
     * @brief Zwraca wiadomość błędu
     * 
     * @return const char* - wiadomość błędu
     */
	const char * what () const throw ()
    {
    	return "Niewłaściwy ruch";
    }
};