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

#include "Tablero.h"

class TableroView
	: public QGraphicsItem
{
	int m_bloque_size;
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

	void moveDerecha()
	{
		m_tablero.moveDer(*m_current);
		update();
	}

	void moveIzquierda()
	{
		m_tablero.moveIzq(*m_current);
		update();
	}

	void rotarDerecha()
	{
		m_tablero.rotarDer(*m_current);
		update();
	}

	void rotarIzquierda()
	{
		m_tablero.rotarIzq(*m_current);
		update();
	}

	void gameOver()
	{
		int ret = QMessageBox::information(0, "T3tr1z", "Game Over!", QMessageBox::Ok, QMessageBox::Ok);
	}

protected:
	void advance(int step)
	{
		if (!step)
			return;
		if (!m_tablero.moveDown(*m_current))
		{
			delete m_current;
			m_current = m_cola.pop();
			if(m_tablero.canRegister())
			{
				m_tablero.registerFigura(*m_current);
				m_tablero.evaluar();
			}
			else
				gameOver();
		}
		update();
	}
};

#endif // TABLERO_VIEW_H
