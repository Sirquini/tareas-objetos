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
#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <QtWidgets>

#include "TableroView.h"

class GameController
	: public QGraphicsView
{
	Q_OBJECT

	QGraphicsScene scene;
	QTimer timer; // Contador de tiempo.
    TableroView m_tbl_view; // Vista del tablero.

public:
	GameController(int rows, int cols, int size = 20) // Contructor del controlador
        : m_tbl_view(rows, cols, size)
    {
        scene.setSceneRect(0 , 0, cols * size, rows * size);
        setScene(&scene);
        scene.addItem(&m_tbl_view);
        setRenderHint(QPainter::Antialiasing);
        setWindowTitle("T3tr1z ~Sirquini");
        resize(cols * size + 10, rows * size + 10);
        show();
        QObject::connect(&timer, &QTimer::timeout, &scene, &QGraphicsScene::advance);
        timer.start(1000);
    }

    virtual ~GameController(){}
protected:
    void keyPressEvent(QKeyEvent *event) // Responder a las entradas de teclado para mover la Figura.
    {
        switch (event->key()) {
            case Qt::Key_Left:
                m_tbl_view.moveIzquierda();
                break;
            case Qt::Key_Right:
                m_tbl_view.moveDerecha();
                break;
            case Qt::Key_Up:
                m_tbl_view.rotarIzquierda();
                break;
            case Qt::Key_Down:
                m_tbl_view.rotarDerecha();
                break;
            default:
              QWidget::keyPressEvent(event);
          }
    }
};

#endif // GAME_CONTROLLER_H
