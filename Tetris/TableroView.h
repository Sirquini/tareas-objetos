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
#ifndef TABLERO_VIEW_H
#define TABLERO_VIEW_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QMessageBox>
#include <QApplication>

#include "Tablero.h"

class TableroView
	: public QGraphicsItem
{
	int m_bloque_size; // Tamano en pixeles de un Bloque  o cuadrado.
	int m_rows, m_cols; // Numero de filas y columnas para el dibujado del Tablero.
	Cola m_cola; // Cola de Figuras del juego
	Tablero m_tablero; // Tablero de figuras
	Figura* m_current; // Figura actual en el tablero, para manejo de memoria.

public:
	TableroView(int rows, int cols, int size = 20) // Contructor de la vista
		: m_bloque_size(size), m_rows(rows), m_cols(cols), m_cola(1), m_tablero(rows, cols, m_cola)
	{
		setPos(0,0);
		setFlag(ItemIsFocusable);
		grabKeyboard();
		m_current = m_cola.pop();
		m_tablero.registerFigura(*m_current);
	}

	QRectF boundingRect() const
	{
		return QRectF(0, 0, m_cols * m_bloque_size, m_rows * m_bloque_size);
	}

	QPainterPath shape() const
	{
		QPainterPath path;
		path.addRect(0, 0, m_cols * m_bloque_size, m_rows * m_bloque_size);
		return path;
	}

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
				QWidget *widget)
	{
		int x, y = 0;
		painter->setBrush(QColor(0, 102, 255));
		for(auto& row : m_tablero.getTablero())
		{
			x = 0;
			for(auto it = row.begin(); it != row.end(); ++it)
			{
				if(*it)
					painter->drawRect(x, y, m_bloque_size, m_bloque_size);
				x += m_bloque_size;
			}
			y += m_bloque_size;
		}
	}
	/* Mueve a la derecha una Figura en el Tablero, de ser posible y actualiza la pantalla. */
	void moveDerecha()
	{
		m_tablero.moveDer(*m_current);
		update();
	}
	/* Mueve a la izquierda una Figura en el Tablero, de ser posible y actualiza la pantalla. */
	void moveIzquierda()
	{
		m_tablero.moveIzq(*m_current);
		update();
	}
	/* Rota a la derecha una Figura en el Tablero, de ser posible y actualiza la pantalla. */
	void rotarDerecha()
	{
		m_tablero.rotarDer(*m_current);
		update();
	}
	/* Rota a la izquierda una Figura en el Tablero, de ser posible y actualiza la pantalla. */
	void rotarIzquierda()
	{
		m_tablero.rotarIzq(*m_current);
		update();
	}
	/* Avisa que el juego esta terminado, y cierra la aplicacion. */
	void gameOver()
	{
		QMessageBox::information(0, "T3tr1z", "Game Over!", QMessageBox::Ok, QMessageBox::Ok);
		QApplication::exit();
	}

protected:
	/* Funcion de avance, refresca la pantalla con el nuevo estado del Tablero */
	void advance(int step)
	{
		if (!step)
			return;
		if (!m_tablero.moveDown(*m_current)) // Mueve la actual Figura hacia abajo.
		{
			delete m_current; // De no poder mover hacia abajo libera memoria.
			m_tablero.evaluar(); // Evaluamos el tablero.
			if(m_tablero.canRegister()) // Checkeamo si podemos generar otra Figura.
			{
				m_current = m_cola.pop(); // Nueva Figura.
				m_tablero.registerFigura(*m_current); // La registramos en el Tablero.
				update();
			}
			else
				gameOver(); // De no poder poner mas figuras, se acaba el juego.
		}
		else
			update();
	}
};

#endif // TABLERO_VIEW_H
