#ifndef TECLADOWIN
#define TECLADOWIN

#include "InterfaceIn.h"

class TecladoWin : public InterfaceIn {
		
	public:
		int getInput(); 					// override. testando isso para criar punteiro de função virtual
		int getOperatorPassword();
		int getInputOperator();
};

#endif		// TECLADOWIN