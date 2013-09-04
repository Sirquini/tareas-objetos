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
#ifndef Figura_h
#define Figura_h

#include <vector>
#include <iostream>
#include <cassert>

#include "Bloque.h"


class Figura {

 public:
	std::vector< Bloque > m_bloques;

	Figura()
	{
		m_bloques.resize(4);
	}

	Figura(int x)
	{
		assert(x >= 0 && x < 7); // Hay 7 figuras en un juego de Tetris normal.
		m_bloques.resize(4);
		if (x == 0)
		{	/* Cuadrado */
			m_bloques = {{0,0}, {1,0}, {0,1}, {1,1}};
		}
		else if (x == 1)
		{	/* Linea */
			m_bloques = {{0,0}, {0,1}, {0,2}, {0,3}};
		}
		else if (x == 2)
		{	/* Figura L */
			m_bloques = {{0,0}, {0,1}, {0,2}, {1,2}};
		}
		else if (x == 3)
		{	/* Figura Z */
			m_bloques = {{0,0}, {1,0}, {1,1}, {2,1}};
		}
		else if (x == 4)
		{	/* Figura L invertida */
			m_bloques = {{1,0}, {1,1}, {1,2}, {0,2}};
		}
		else if (x == 5)
		{	/* Figura Z invertida */
			m_bloques = {{1,0}, {2,0}, {0,1}, {1,1}};
		}
		else
		{	/* Figura T */
			m_bloques = {{0,0}, {1,0}, {2,0}, {1,1}};
		}
	}

	void rotar()
	{
		int x = m_bloques[1].getX();
		int y = m_bloques[1].getY();

		for (auto& bloque : m_bloques)
			bloque.setPair(-bloque.getY() + y + x, bloque.getX() - x + y);
	}

	void moveDer()
	{
		for(auto& bloque : m_bloques)
			bloque.setX(bloque.getX() + 1);
	}

	void moveIzq()
	{
		for(auto& bloque : m_bloques)
			bloque.setX(bloque.getX() - 1);
	}

	void moveDown()
	{
		for(auto& bloque : m_bloques)
			bloque.setY(bloque.getY() + 1);
	}

	void print() const
	{
		std::cout << "==[Figura]==" << std::endl;
		for (auto const bloque : m_bloques)
			std::cout << "(" << bloque.getX() << "," << bloque.getY() << ")" << std::endl;
	}

	~Figura() {}

};

#endif // Figura_h
