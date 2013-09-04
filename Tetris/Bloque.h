/*     #######             #####         
 *  #############       ###########      
 * ####       ####    ####       ####    
 *###           ###  ###           ###   
 * ####              ###           ###   
 *   #####           ###           ###   
 *     #####         ###           ###   
 *       #####       ###  ##       ###   
 *         #####     ###  ####     ###   
 *           #####   ###    ####   ###   
 *###           ###  ###      #### ###   
 * ####       ####    ####      #####    
 *  #############       ###############
 *     #######             #####    ####
 *     Creado por: Santiago Quintero     
 */

#ifndef Bloque_h
#define Bloque_h

#include <iostream>

/* Clase Bloque representa un par de coordenadas dentro de un bloque de Tetris dentro de una matriz */
class Bloque {

 public:
    int m_x, m_y; // Posicion de coordenas (x,y)

    /* Constructor de un bloque por defecto (0,0) */
    Bloque()
    	: m_x(0), m_y(0)
    {}

    /* Inicializa el bloque con las coordenadas (x,y) */
	Bloque(int x, int y)
		: m_x(x), m_y(y)
	{}

	int getX() const { return m_x; }

	int getY() const { return m_y; }

	void setX(int x){ m_x = x; }

	void setY(int y){ m_y = y; }

	void setPair(int x, int y) // Asigna los valores x,y como nuevas coordenadas del Bloque
	{
		setX(x);
		setY(y);
	}

	/* Permite realizar comparar cuando dos bloques son iguales, i.e, cuando sus coordenadas x,y son iguales */
	bool operator== (const Bloque& b) const
	{
		return (m_x == b.getX() && m_y == b.getY());
	}

	/* Imprime las coordenas (x,y) del Bloque */
	void print() const
	{
		std::cout << "(" << m_x << ", " << m_y << ")" << std::endl;
	}

};

#endif // Bloque_h
