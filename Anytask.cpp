#include <iostream>
using namespace std;

#define INTERFACE 3 // 1 = LINUX-PC  || 2 = ATLYS || 2 = WINDOWS-PC

#include "Anytask.h"
#if INTERFACE == 1 // Using PC
#include "TecladoPc.cpp"
#elif INTERFACE == 2 // Using Atlys
#include "TecladoAtlys.cpp"
#else
#include "TecladoWin.cpp"
#endif



//--------------------------------------------------------
Anytask::Anytask(){};
//--------------------------------------------------------
Anytask::~Anytask(){};
//--------------------------------------------------------
void Anytask::inputData()
{
    int value;
    cout << "TASK PRIORITY 2: Input integer value: ";

#if INTERFACE == 1 // Using PC (diretivas de compilação para processdor)
    pEntrada = new TecladoPc();
#elif INTERFACE == 2 // Using Atlys
    pEntrada = new TecladoAtlys();
#else
    pEntrada = new TecladoWin();
#endif

    Timer objTimer;
    int output = 1;
    int option;
    //cout << " asd ASD ASDAS DSAD AS:   " << objTimer.start(1000);

    while (output != 0)
    {
        output = objTimer.start(1);
        option = pEntrada->getInput();
    }
    cout << endl
         << endl;
};
//--------------------------------------------------------
void Anytask::hello()
{
    cout << "TASK PRIORITY 0: Hello scheduler" << endl
         << endl;
};
//--------------------------------------------------------
void Anytask::newFunction()
{
    cout << "TASK PRIORITY 1: New message for testing" << endl
         << endl;
};