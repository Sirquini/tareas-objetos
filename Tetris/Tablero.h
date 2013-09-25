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

/* Clase principal, representa el tablero de tetris y los metodos principales del juego. */
class Tablero {

	std::vector< Bloque > m_bloques; //Referencia a los bloques en el tablero.
	std::vector< std::vector< bool > > m_tablero; // Matriz del tablero.
	Cola m_cola; // Cola que genera la siguiente figura.
	size_t rows, cols; // Numero de Filas y Columnas del tablero.

 public:
	Tablero() //Constructora por defecto.
		: rows{0}, cols{0}
	{ }

	/* Constructora del tablero, recibe el numero de filas, columnas y la cola para generar figuras,
	 * inicializa la matriz del tablero. */
	Tablero(size_t n_rows, size_t n_cols, const Cola& cola)
		: m_tablero{n_rows}, rows{n_rows}, cols{n_cols} 
	{
		m_cola = cola;
		for (auto& row : m_tablero)
			row.resize(n_cols);
	}

	/* Retorna la Cola generadora que utiliza el tablero */
	Cola getCola() const
	{ return m_cola; }

	/* Genera y retorna una nueva Figura sin registrar en la matrix del Tablero. */
	Figura* getFigura()
	{ return m_cola.pop(); }

	/* Rota los Bloques de una Figura en sentido horario y actualiza la matriz del Tablero
	 * Retorna: true si la rotacion es valida, o false de no ser posible. */
	bool rotarDer(Figura& figura)
	{
		int x, y; // Posiciones absolutas de un Bloque en el tablero.
		bool r_valida = true; // Indica la validez de la rotacion.
		unregisterFigura(figura); // Borramos la Figura de la matriz del Tablero.
		figura.rotarDer(); // Realizamos la rotacion de cada Bloque.
		for(auto& bloque : figura.m_bloques) // Revisamos que los Bloques esten en una posicion valida.
		{
			x = bloque.getX() + figura.m_x;
			y = bloque.getY() + figura.m_y;
			if (x >= cols || x < 0 || y >= rows || y < 0 || m_tablero[y][x] )
			{
				figura.rotarIzq(); // De haber una posicion invalida, revertimos la rotacion.
				r_valida = false; // Indicamos una rotacion invalida.
				break;
			}
		}
		registerFigura(figura); // Actualizamos el tablero con la nueva posicion de los bloques.
		return r_valida; // Retornamos la validez de la rotacion.
	}

	/* Rota los Bloques de una Figura en sentido anti-horario y actualiza la matriz del Tablero
	 * Retorna: true si la rotacion es valida, o false de no ser posible. */
	bool rotarIzq(Figura& figura)
	{
		int x, y; // Posiciones absolutas de un Bloque en el tablero.
		bool r_valida = true; // Indica la validez de la rotacion.
		unregisterFigura(figura); // Borramos la Figura de la matriz del Tablero.
		figura.rotarIzq(); // Realizamos la rotacion de cada Bloque.
		for(auto& bloque : figura.m_bloques) // Revisamos que los Bloques esten en una posicion valida.
		{
			x = bloque.getX() + figura.m_x;
			y = bloque.getY() + figura.m_y;
			if (x >= cols || x < 0 || y >= rows || y < 0 || m_tablero[y][x] )
			{
				figura.rotarDer(); // De haber una posicion invalida, revertimos la rotacion.
				r_valida = false; // Indicamos una rotacion invalida.
				break;
			}
		}
		registerFigura(figura); // Actualizamos el tablero con la nueva posicion de los bloques.
		return r_valida; // Retornamos la validez de la rotacion.
	}

	/* Mueve los Bloques de una Figura a la derecha y actualiza la matriz del Tablero
	 * Retorna: true si la traslacion es valida, o false de no ser posible. */
	bool moveDer(Figura& figura)
	{
		bool t_valida = true; // Indica la validez de la traslacion.
		unregisterFigura(figura); // Borramos la Figura de la matriz del Tablero.
		figura.moveDer(); // Realizamos la traslacion de cada Bloque.
		for (auto& bloque : figura.m_bloques) // Revisamos que cada Bloque este en una posicion valida.
		{
			if (bloque.getX() + figura.m_x >= cols || m_tablero[bloque.getY() + figura.m_y][bloque.getX() + figura.m_x])
			{
				figura.moveIzq(); // De haber una posicion invalida, revertimos la traslacion.
				t_valida = false; // Indicamos una traslacion invalida.
				break;
			}
		}
		registerFigura(figura); // Actualizamos la matriz del Tablero con la nueva posicion de cada Bloques.
		return t_valida; // Retornamos la validez de la traslacion.
	}

	/* Mueve los Bloques de una Figura a la izquierda y actualiza la matriz del Tablero
	 * Retorna: true si la traslacion es valida, o false de no ser posible. */
	bool moveIzq(Figura& figura)
	{
		bool t_valida = true; // Indica la validez de la traslacion.
		unregisterFigura(figura); // Borramos la Figura de la matriz del Tablero.
		figura.moveIzq(); // Realizamos la traslacion de cada Bloque.
		for (auto& bloque : figura.m_bloques) // Revisamos que cada Bloque este en una posicion valida.
		{
			if (bloque.getX() + figura.m_x < 0 || m_tablero[bloque.getY() + figura.m_y][bloque.getX() + figura.m_x])
			{
				figura.moveDer(); // De haber una posicion invalida, revertimos la traslacion.
				t_valida = false; // Indicamos una traslacion invalida.
				break;
			}
		}
		registerFigura(figura); // Actualizamos la matriz del Tablero con la nueva posicion de cada Bloques.
		return t_valida; // Retornamos la validez de la traslacion.
	}

	/* Mueve una Figura hacia abajo en la matriz del tablero
	 * Retorna: true si la traslacion es valida, o false de no ser posible. */
	bool moveDown(Figura& figura)
	{
		int x,y; // Posiciones absolutas de un Bloque en la matriz del Tablero.
		bool t_valida = true; // Indica la validez de la traslacion.
		unregisterFigura(figura); // Borramos la Figura de la matriz del Tablero.
		for (auto& bloque : figura.m_bloques) // Revisamos que cada Bloque se mueva a una posicion valida.
		{
			x = bloque.getX() + figura.m_x;
			y = bloque.getY() + figura.m_y + 1;
			if (y >= rows || m_tablero[y][x])
			{
				--figura.m_y; // Contrarestamos la traslacion de la figura.
				t_valida = false; // Indicamos una traslacion invalida.
				break;
			}
		}
		figura.moveDown(); // Realizamos la traslacion de la Figura.
		registerFigura(figura); // Actualizamos la matriz del Tablero con la nueva posicion de cada Bloques.
		return t_valida; // Retornamos la validez de la traslacion.
	}

	/* Evalua si hay filas llenas de Bloques en la matriz del Tablero para eliminarlos */
	void evaluar()
	{
		bool tmp;
		int i,j;
		for (i = 0; i < rows; ++i)
		{
			tmp = true;
			for (j = 0; j < cols; ++j)
			{
				tmp = tmp && m_tablero[i][j];
			}
			if (tmp)
			{
				m_tablero[i].assign(cols, false);
			}
		}
	}

	/* Elimina la posicion de cada Bloque de una Figura de la matriz del Tablero */
	void unregisterFigura(const Figura& figura)
	{
		for(auto& bloque : figura.m_bloques)
			m_tablero[bloque.getY() + figura.m_y][bloque.getX() + figura.m_x] = false;
	}

	/* Agrega la posicion de cada Bloque de una Figura en la matriz del Tablero */
	void registerFigura(const Figura& figura)
	{
		for(auto& bloque : figura.m_bloques)
			m_tablero[bloque.getY() + figura.m_y][bloque.getX() + figura.m_x] = true;
	}

	/* Imprime en pantalla la representacion del estado actual del Tablero de Tetriz  */
	void print() const
	{
		std::cout << "==[Tablero]==" << std::endl;
		for (auto row : m_tablero)
		{
			for (auto cell : row)
				std::cout << ((cell) ? "X" : " ");
			std::cout << std::endl;
		}
	}
};

#endif // Tablero_h
