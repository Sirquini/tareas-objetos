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
	Cola cola;
	Tablero tablero(20 , 10, cola);

	tablero.print();

	// Comparacion de bloques
	// Bloque b1(0,0);
	// Bloque b2(0,0);
	// Bloque b3(0,1);

	// std::cout << "b1 == b2: " << ((b1 == b2) ? "True":"False") << std::endl;
	// std::cout << "b1 == b3: " << ((b1 == b3) ? "True":"False") << std::endl;

	// Figura test1(1);

	// std::cout << "Test Figura" << std::endl;
	// // imprimo las posiciones iniciales
	// test1.print();
	// // mover a la derecha dos veces
	// test1.moveDer();
	// test1.moveDer();
	// // mover hacia abajo una vos
	// test1.moveDown();
	// // imprimo la figura trasladada
	// test1.print();
	// // rotamos la figura a la derecha
	// test1.rotar();
	// // imprimo las nuevas posiciones
	// test1.print();

	// Cola cola;
	// Figura* test2 = cola.pop();

	// std::cout << "Test Figura de Cola 1" << std::endl;

	// test2->moveDer();
	// test2->moveDer();
	// test2->moveDer();
	// test2->moveDown();
	// test2->print();
	// test2->rotar();
	// test2->print();

	// delete test2;

	// std::cout << "Test Figura de Cola 2" << std::endl;
	// test2 = cola.pop();

	// test2->moveDer();
	// test2->moveDer();
	// test2->moveDer();
	// test2->moveDown();
	// test2->print();
	// test2->rotar();
	// test2->print();

	// delete test2;

	return 0;
}
