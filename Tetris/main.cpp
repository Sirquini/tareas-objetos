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
#include "GameController.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	// Filas, Columnas, Tamano (pixeles) por celda.
	GameController gameCtrl(20, 10);

	return app.exec();
}
