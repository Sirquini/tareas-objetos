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
	std::vector< Bloque* > m_bloques;
	std::vector< std::vector< bool > > m_tablero;
	Cola m_cola;
	size_t rows, cols;

	Tablero()
		: rows{0}, cols{0}
	{ }

	Tablero(size_t n_rows, size_t n_cols, const Cola& cola)
		: m_tablero{n_rows}, rows{n_rows}, cols{n_cols} 
	{
		m_cola = cola;
		for (auto& row : m_tablero)
			row.resize(n_cols);
	}

	Cola getCola() const
	{ 
		return m_cola;
	}

	Figura* getFigura()
	{
		return m_cola.pop();
	}

	void registerFigura(const Figura& figura)
	{

	}

	void print() const
	{
		for (auto row : m_tablero)
		{
			for (auto cell : row)
			{
				if (cell)
					std::cout << "X";
				else
					std::cout << " ";
			}
			std::cout << std::endl;
		}
	}
};

#endif // Tablero_h
