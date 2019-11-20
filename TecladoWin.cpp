#include <Windows.h>
#include<iostream>
#include <string>
using namespace std;

#include "InterfaceIn.cpp"
#include "TecladoWin.h"

int TecladoWin::getInput(){
	cout << "FLAG TEST: into TECLADOWIN::getInput" ;
		if (GetKeyState('1') & 0x8000)
        {
            cout << setfill('.') << setw(45) << "Entrada detectada" << endl;
            optionUser = 1;
        }
        else if (GetKeyState('2') & 0x8000)
        {
            cout << setfill('.') << setw(45) << "Entrada detectada" << endl;
            optionUser = 2;
        }
	
	return optionUser;
};


int TecladoWin::getInputOperator(){

		do{
			try{
				cin >> optionOperator;
				if(optionOperator < 0 || optionOperator > 5)
					throw 1;
			}
			catch(int i){
				cout << "Erro, opção inválida"<<endl;
			}
			catch(...){
				cout << "Opção imprevista."<<endl;
			}
		}while(optionOperator < 0 && optionOperator >5);	
	
	return optionOperator;
};

int TecladoWin::getOperatorPassword(){
	cout << "FLAG TEST: into getOperatorPassword" << endl;
	cin >> operatorPassword;
	return operatorPassword;
};