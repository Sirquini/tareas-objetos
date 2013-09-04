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

	/* Inicializa el vector de Bloques en 4 Bloques (0,0) */
	Figura()
	{
		m_bloques.resize(4);
	}

	/* Inicializa una Figura con las coordenas iniciales de 4 Bloques, dependiendo la forma de la Figura, x [0,6]*/
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

	/* Rota una Figura en sentido de las manecillas del reloj,
	 * con el segundo bloque como centro de rotacion.
	 */
	void rotar()
	{
		// Coordenadas x,y del centro de rotacion.
		int x = m_bloques[1].getX();
		int y = m_bloques[1].getY();

		for (auto& bloque : m_bloques)
			bloque.setPair(-bloque.getY() + y + x, bloque.getX() - x + y);
	}

	/* Mueve los Bloques de una Figura una posicion hacia el lado positivo del eje x*/
	void moveDer()
	{
		for(auto& bloque : m_bloques)
			bloque.setX(bloque.getX() + 1);
	}

	/* Mueve los Bloques de una Figura una posicion hacia el lado negativo del eje x*/
	void moveIzq()
	{
		for(auto& bloque : m_bloques)
			bloque.setX(bloque.getX() - 1);
	}

	/* Aumenta en 1 la posicion y de los Bloques que componen la Fiogura */
	void moveDown()
	{
		for(auto& bloque : m_bloques)
			bloque.setY(bloque.getY() + 1);
	}

	/* Imprime las coordenadas x,y de cada Bloque que compone la Figura*/
	void print() const
	{
		std::cout << "==[Figura]==" << std::endl;
		for (auto const bloque : m_bloques)
			bloque.print();
	}

	~Figura() {}

};

#endif // Figura_h
