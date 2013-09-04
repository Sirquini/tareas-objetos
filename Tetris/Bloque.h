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

#ifndef Bloque_h
#define Bloque_h

#include <iostream>

class Bloque {

 public:
    int m_x, m_y;

    Bloque()
    	: m_x(0), m_y(0)
    {}

	Bloque(int x, int y)
		: m_x(x), m_y(y)
	{}

	int getX() const { return m_x; }

	int getY() const { return m_y; }

	void setX(int x){ m_x = x; }

	void setY(int y){ m_y = y; }

	void setPair(int x, int y)
	{
		setX(x);
		setY(y);
	}

	bool operator== (const Bloque& b) const
	{
		return (m_x == b.getX() && m_y == b.getY());
	}

	void print() const
	{
		std::cout << m_x << ", " << m_y << std::endl;
	}

};

#endif // Bloque_h
