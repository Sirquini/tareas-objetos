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

#include "Figura.h"
#include "Cola.h"

int main(int argc, char const *argv[])
{
	Figura test1(1);

	// imprimo las posiciones iniciales
	test1.print();

	// rotamos la figura a la derecha
	test1.rotar();

	// imprimo las nuevas posiciones
	test1.print();

	Cola cola;
	Figura* test2 = cola.pop();
	test2->print();

	delete test2;

	test2 = cola.pop();
	test2->print();

	delete test2;

	return 0;
}