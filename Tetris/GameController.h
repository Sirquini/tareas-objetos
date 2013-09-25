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
	QTimer timer;
    TableroView m_tbl_view; // Vista del tablero.

public:
	GameController() // Contructor del controlador
    {
        scene.setSceneRect(0 , 0, 400, 500);
        setScene(&scene);
        scene.addItem(&m_tbl_view);
        setRenderHint(QPainter::Antialiasing);
        setWindowTitle("T3tr1z ~Sirquini");
        resize(410, 510);
        show();
        QObject::connect(&timer, &QTimer::timeout, &scene, &QGraphicsScene::advance);
        timer.start(1000);
    }

    virtual ~GameController(){}
protected:
    void keyPressEvent(QKeyEvent *event)
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
