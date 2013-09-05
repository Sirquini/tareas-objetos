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
	int m_x, m_y; //Coordenadas absolutas (respecto a una matriz)

	/* Inicializa el vector de Bloques en 4 Bloques (0,0) */
	Figura()
		: m_x(0), m_y(0)
	{
		m_bloques.resize(4);
	}

	/* Inicializa una Figura con las coordenas iniciales de 4 Bloques, dependiendo la forma de la Figura, x [0,6]*/
	Figura(int x)
		: m_x(0), m_y(0)
	{
		assert(x >= 0 && x < 7); // Hay 7 figuras en un juego de Tetris normal.
		m_bloques.resize(4);
		switch(x)
		{
			/* Cuadrado */
			case 0:	m_bloques = {{0,0}, {1,0}, {0,1}, {1,1}}; break;
			/* Linea */
			case 1: m_bloques = {{0,0}, {0,1}, {0,2}, {0,3}}; break;
			/* Figura L */
			case 2:	m_bloques = {{0,0}, {0,1}, {0,2}, {1,2}}; break;
			/* Figura Z */
			case 3:	m_bloques = {{0,0}, {1,0}, {1,1}, {2,1}}; break;
			/* Figura L invertida */
			case 4:	m_bloques = {{1,0}, {1,1}, {1,2}, {0,2}}; break;
			/* Figura Z invertida */
			case 5:	m_bloques = {{1,0}, {2,0}, {0,1}, {1,1}}; break;
			/* Figura T */
			case 6: m_bloques = {{0,0}, {1,0}, {2,0}, {1,1}};
		}
	}

	/* Rota una Figura en sentido de las manecillas del reloj. */
	void rotarDer()
	{
		for (auto& bloque : m_bloques)
			bloque.setPair(-bloque.getY(), bloque.getX());
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
		for (auto& bloque : m_bloques)
			bloque.print();
	}

};

#endif // Figura_h
