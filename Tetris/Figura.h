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
		m_bloques.resize(4); // Redimenciona el vector a 4 Bloques
	}

	/* Inicializa una Figura con las coordenas iniciales de 4 Bloques, dependiendo la forma de la Figura, x [0,6]*/
	Figura(int x)
		: m_x(0), m_y(0)
	{
		assert(x >= 0 && x < 7); // Hay 7 figuras en un juego de Tetris normal.
		m_bloques.resize(4); // Redimenciono el vector para contener 4 Bloques
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

	/* Rota una Figura en sentido antihorario. */
	void rotarIzq()
	{
		for (auto& bloque : m_bloques)
			bloque.setPair(bloque.getY(), -bloque.getX());
	}

	/* Mueve la Figura una posicion hacia el lado positivo del eje x*/
	void moveDer() { ++m_x;	}

	/* Mueve la Figura una posicion hacia el lado negativo del eje x*/
	void moveIzq() { --m_x; }

	/* Aumenta en 1 la posicion y de la Fiogura */
	void moveDown()	{ ++m_y; }

	/* Imprime las coordenadas x,y de cada Bloque que compone la Figura*/
	void print() const
	{
		std::cout << "==[Figura(" << m_x << "," << m_y << ")]==" << std::endl;
		for (auto& bloque : m_bloques)
			bloque.print();
	}

    virtual ~Figura(){}

	// friend std::ostream& operator<< (std::ostream& o, Figura& f);

};

// std::ostream& operator<< (std::ostream& o, Figura& f)
// {
// 	o << "==[Figura(" << f.m_x << "," << f.m_y << ")]==" << std::endl;
// 		for (auto& bloque : f.m_bloques)
// 			o << bloque << std::endl;
// 	return o;
// }

class Cuadrado
	: public Figura
{
public:
	Cuadrado()
	{
		m_x = 0; m_y = 0;
		m_bloques = {{0,0}, {1,0}, {0,1}, {1,1}};
	}

	~Cuadrado(){}

};

class Linea
	: public Figura
{
public:
	Linea()
	{
		m_x = 0; m_y = 0;
		m_bloques = {{0,0}, {0,1}, {0,2}, {0,3}};
	}

	~Linea(){}

};

class FiguraL
	: public Figura
{
public:
	FiguraL()
	{
		m_x = 0; m_y = 1;
		m_bloques = {{0,-1}, {0,0}, {0,1}, {1,1}};
	}

	~FiguraL(){}

};

class FiguraLI
	: public Figura
{
public:
	FiguraLI()
	{
		m_x = 1; m_y = 1;
		m_bloques = {{0,-1}, {0,0}, {0,1}, {-1,1}};
	}

	~FiguraLI(){}

};

class FiguraZ
	: public Figura
{
public:
	FiguraZ()
	{
		m_x = 1; m_y = 0;
		m_bloques = {{-1,0}, {0,0}, {0,1}, {1,1}};
	}

	~FiguraZ(){}

};

class FiguraZI
	: public Figura
{
public:
	FiguraZI()
	{
		m_x = 2; m_y = 0;
		m_bloques = {{-1,0}, {0,0}, {-2,1}, {-1,1}};
	}

	~FiguraZI(){}

};

class FiguraT
	: public Figura
{
public:
	FiguraT()
	{
		m_x = 1; m_y = 0;
		m_bloques = {{-1,0}, {0,0}, {1,0}, {0,1}};
	}

	~FiguraT(){}

};

#endif // Figura_h
