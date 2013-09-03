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
		assert(x >= 0 && x < 7);
		m_bloques.resize(4);
		if (x == 0)
		{
			/* Cuadrado */
			m_bloques[0].setPair(0,0);
			m_bloques[1].setPair(1,0);
			m_bloques[2].setPair(0,1);
			m_bloques[3].setPair(1,1);
		}
		else if (x == 1)
		{
			/* Linea */
			m_bloques[0].setPair(0,0);
			m_bloques[1].setPair(0,1);
			m_bloques[2].setPair(0,2);
			m_bloques[3].setPair(0,3);
		}
		else if (x == 2)
		{
			/* Figura L */
			m_bloques[0].setPair(0,0);
			m_bloques[1].setPair(0,1);
			m_bloques[2].setPair(0,2);
			m_bloques[3].setPair(1,2);
		}
		else if (x == 3)
		{
			/* Figura Z */
			m_bloques[0].setPair(0,0);
			m_bloques[1].setPair(1,0);
			m_bloques[2].setPair(1,1);
			m_bloques[3].setPair(2,1);
		}
		else if (x == 4)
		{
			/* Figura L invertida */
			m_bloques[0].setPair(1,0);
			m_bloques[1].setPair(1,1);
			m_bloques[2].setPair(1,2);
			m_bloques[3].setPair(0,2);
		}
		else if (x == 5)
		{
			/* Figura Z invertida */
			m_bloques[0].setPair(1,0);
			m_bloques[1].setPair(2,0);
			m_bloques[2].setPair(0,1);
			m_bloques[3].setPair(1,1);
		}
		else
		{
			/* Figura T */
			m_bloques[0].setPair(0,0);
			m_bloques[1].setPair(1,0);
			m_bloques[2].setPair(2,0);
			m_bloques[3].setPair(1,1);
		}
	}

	void rotar()
	{
		for (auto& bloque : m_bloques)
		{
			bloque.setPair(-bloque.getY(), bloque.getX());
		}
	}

	void print() const
	{
		std::cout << "==[Figura]==" << std::endl;
		std::cout << "(" << m_bloques[0].getX() << "," << m_bloques[0].getY() << ")" << std::endl;
		std::cout << "(" << m_bloques[1].getX() << "," << m_bloques[1].getY() << ")" << std::endl;
		std::cout << "(" << m_bloques[2].getX() << "," << m_bloques[2].getY() << ")" << std::endl;
		std::cout << "(" << m_bloques[3].getX() << "," << m_bloques[3].getY() << ")" << std::endl;
	}

};

#endif // Figura_h
