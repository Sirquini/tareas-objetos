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

#ifndef Tablero_h
#define Tablero_h

#include <vector>

#include "Bloque.h"
#include "Cola.h"


class Tablero {

 public:
	std::vector< Bloque > m_tablero;
	Cola m_cola;
	size_t rows, cols;

	Tablero()
		: rows{0}, cols{0}
	{ }

	Tablero(size_t n_rows, size_t n_cols, const Cola& cola)
		: rows{n_rows}, cols{n_cols} 
	{
		m_cola = cola;
	}

	Cola getCola() const
	{ 
		return m_cola;
	}

	Figura* getFigura()
	{
		return m_cola.pop();
	}

	void print() const
	{
		int x, y;
		for(y = 0; y < rows; ++y)
		{
			for(x = 0; x < cols; ++x)
			{
				for(const auto& bloque : m_tablero)
				{
					if(Bloque::Bloque(x,y) == bloque)
					{
						std::cout << "x";
						break;
					}
					else
						std::cout << " ";
				}
			}
		}
	}
};

#endif // Tablero_h
