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


class Cola {

public:
	std::uniform_int_distribution<int> distribution;
	std::mt19937 generator;
	
	Cola()
		: distribution(0,6), generator(time(NULL))
	{}

	void push(Figura figura){}

	Figura* pop()
	{
		return new Figura(distribution(generator));
	}

};

#endif // Cola_h
