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
#include "Tablero.h"


int main(int argc, char const *argv[])
{
	Cola cola(3);
	Tablero tablero(14 , 10, cola);

	tablero.print();
	Figura* figura = tablero.getFigura();
	Figura linea(1);

	tablero.registerFigura(linea);
	tablero.print();

	tablero.rotarIzq(linea);
	tablero.moveDown(linea);
	tablero.moveDown(linea);
	tablero.moveDown(linea);
	tablero.moveDown(linea);
	tablero.moveDown(linea);
	tablero.moveDown(linea);
	tablero.moveDown(linea);
	tablero.moveDown(linea);
	tablero.moveDown(linea);
	tablero.moveDown(linea);
	tablero.moveDown(linea);
	tablero.moveDown(linea);
	tablero.print();

	std::cout << figura;
	tablero.registerFigura(*figura);
	tablero.moveIzq(*figura);
	tablero.moveDer(*figura);
	tablero.moveDown(*figura);
	tablero.moveDown(*figura);
	tablero.moveDown(*figura);
	tablero.moveDown(*figura);
	tablero.moveDown(*figura);
	tablero.moveDown(*figura);
	tablero.moveDown(*figura);
	tablero.moveDown(*figura);
	tablero.moveDown(*figura);
	tablero.moveDown(*figura);
	tablero.moveDown(*figura);
	tablero.print();

	tablero.evaluar();
	tablero.print();

	Figura linea2(1);
	Figura cuadrado(0);

	linea2.rotarIzq();
	/* Esta forma de mover figuras no checkea colisiones!
	 * Para checkear coliciones es mejor registrar la figura en
	 * el tablero y luego moverla con los metodos del tablero que
	 * checkean colisiones.
	 */
	linea2.moveDer();
	linea2.moveDer();
	linea2.moveDer();
	linea2.moveDer();
	cuadrado.moveDer();
	cuadrado.moveDer();
	cuadrado.moveDer();
	cuadrado.moveDer();
	cuadrado.moveDer();
	cuadrado.moveDer();
	cuadrado.moveDer();
	cuadrado.moveDer();

	tablero.registerFigura(linea2);
	tablero.moveDown(linea2);
	tablero.moveDown(linea2);
	tablero.moveDown(linea2);
	tablero.moveDown(linea2);
	tablero.moveDown(linea2);
	tablero.moveDown(linea2);
	tablero.moveDown(linea2);
	tablero.moveDown(linea2);
	tablero.moveDown(linea2);
	tablero.moveDown(linea2);
	tablero.moveDown(linea2);
	tablero.moveDown(linea2);

	tablero.registerFigura(cuadrado);
	tablero.moveDown(cuadrado);
	tablero.moveDown(cuadrado);
	tablero.moveDown(cuadrado);
	tablero.moveDown(cuadrado);
	tablero.moveDown(cuadrado);
	tablero.moveDown(cuadrado);
	tablero.moveDown(cuadrado);
	tablero.moveDown(cuadrado);
	tablero.moveDown(cuadrado);
	tablero.moveDown(cuadrado);
	tablero.moveDown(cuadrado);
	tablero.moveDown(cuadrado);

	tablero.print();
	tablero.evaluar();
	tablero.print();

	return 0;
}
