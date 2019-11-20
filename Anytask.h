#ifndef ANYTASK
#define ANYTASK

#include "Timer.h"
#include "InterfaceIn.h"

class Anytask
{
    InterfaceIn* pEntrada;
public:
    Anytask();
    ~Anytask();
    void inputData();
    void hello();
    void newFunction();
    Timer *ptrTimer;
};

#endif //ANYTASK