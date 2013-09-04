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
#include "Figura.h"

/* Generador de Figuras aleatorias, emula las funciones de una cola(push, pop), pero solo genera. */
class Cola {

public:
	std::uniform_int_distribution<int> distribution;
	std::mt19937 generator;
	
	/* Funcion constructuro de la cola, inicializa el genrador de numeros aleatorios
	 * para un rango de [0,6], hay 7 figuras posibles.
	 */
	Cola()
		: distribution(0,6), generator(time(NULL))
	{}

	/* Emula la funcion push() de una cola */
	void push(const Figura& figura) const {}

	/* Genera y retorna un puntero a una Figura aleatoria, la memoria debe ser liberada al terminar de usar la Figura */
	Figura* pop()
	{
		return new Figura(distribution(generator));
	}

};

#endif // Cola_h
