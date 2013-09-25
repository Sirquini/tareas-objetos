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

#ifndef Cola_h
#define Cola_h

#include <random>
#include <functional>
#include <ctime>
#include <queue>
#include "Figura.h"

/* Generador de Figuras aleatorias, emula las funciones de una cola(push, pop), pero solo genera. */
class Cola {

	std::uniform_int_distribution<int> distribution;
	std::mt19937 generator;
	std::queue< Figura* > m_cola;
	
public:
	/* Funcion constructuro de la cola, inicializa el genrador de numeros aleatorios
	 * para un rango de [0,6], hay 7 figuras posibles.
	 */
	Cola()
		: distribution(0,6), generator(time(NULL))
	{}

	/* LLena una Cola con n elementos por defecto. */
	Cola(int n)
		: Cola()
	{
		while(n > 0)
		{
			pushRand(distribution(generator));
			--n;
		}
	}

	/* Adiciona una Figura* figura al final de la Cola */
	void push(Figura* figura) {	m_cola.push(figura); }

	/* Utilidad para adicionar Figuras aleatorias */
	void pushRand(const int& f)
	{
		assert(f >= 0 && f < 7); // Hay 7 figuras en un juego de Tetris normal.
		switch(f)
		{
			case 0 : push(new Cuadrado()); break;
			case 1 : push(new Linea()); break;
			case 2 : push(new FiguraL()); break;
			case 3 : push(new FiguraLI()); break;
			case 4 : push(new FiguraZ()); break;
			case 5 : push(new FiguraZI()); break;
			case 6 : push(new FiguraT());
		}
	}

	/* Retorna un puntero a una Figura y genera una nueva aleatoria,
	 * la memoria debe ser liberada al terminar de usar la Figura */
	Figura* pop()
	{
		Figura* result = m_cola.front();
		m_cola.pop();
		pushRand(distribution(generator));
		return result;
	}

};

#endif // Cola_h
