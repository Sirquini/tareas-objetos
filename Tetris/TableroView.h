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

#include "Tablero.h"

class TableroView
    : public QGraphicsItem
{
    Cola m_cola; // Cola de Figuras del juego
    Tablero m_tablero; // Tablero de figuras
    Figura* m_current; // Figura actual en el tablero, para manejo de memoria.

public:
    TableroView() // Contructor de la vista
        : m_cola(1), m_tablero(14, 10, m_cola)
	{
		setPos(0,0);
		setFlag(ItemIsFocusable);
        grabKeyboard();
        m_current = m_cola.pop();
        m_tablero.registerFigura(*m_current);
	}

    QRectF boundingRect() const
    {
        return QRectF(0, 0, 400, 500);
    }

    QPainterPath shape() const
    {
        QPainterPath path;
        path.addRect(0, 0, 400, 500);
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
                    painter->drawRect(x, y, 10, 10);
                ++x;
            }
            ++y;
        }
    }

    void moveDerecha()
    {
        m_tablero.moveDer(*m_current);
    }

    void moveIzquierda()
    {
        m_tablero.moveIzq(*m_current);
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
            m_tablero.registerFigura(*m_current);
            m_tablero.evaluar();
        }
    }
};

#endif // TABLERO_VIEW_H
