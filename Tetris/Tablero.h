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

#ifndef Tablero_h
#define Tablero_h

#include <vector>

#include "Bloque.h"
#include "Cola.h"


class Tablero {

 public:
    std::vector< std::vector< Bloque > > m_tablero;
    Cola m_cola;
};

#endif // Tablero_h
