#include <iostream>
#include <time.h>

using namespace std;

#include "Escalonador.cpp"
#include "Anytask.cpp"

int main()
{
    Escalonador os;
    Anytask objAnytask;
    Anytask *ptrAnytask;

    os.init_Task_Timers();

    void (Anytask::*pHello)() = &Anytask::hello;             // Deitel pg 972
    void (Anytask::*pInputData)() = &Anytask::inputData;
    void (Anytask::*pNewFunction)() = &Anytask::newFunction;
    ptrAnytask = &objAnytask;

    os.addTask(pHello, ptrAnytask, 20, 0); // ready=0 | delay=period=time | enable=1
    os.addTask(pNewFunction, ptrAnytask, 20, 1);
    os.addTask(pInputData, ptrAnytask, 20, 2);

    cout << "**** Init Run_RTC_Scheduler ****" << endl;

    os.Run_RTC_Scheduler();

    cout << "FLAG TEST: After Run_RTC_Scheduler" << endl;

    return 0;
}


/*#include <iostream>
#include <time.h>

using namespace std;

#include "Escalonador.cpp"
#include "Anytask.cpp"

int main()
{
    Escalonador os;
    Anytask objAnytask;
    Anytask *ptrAnytask;

    os.init_Task_Timers();

    void (Anytask::*pHello)() = &Anytask::hello;             // Deitel pg 972
    void (Anytask::*pInputData)() = &Anytask::inputData;
    void (Anytask::*pNewFunction)() = &Anytask::newFunction;
    ptrAnytask = &objAnytask;

    os.addTask(pHello, ptrAnytask, 30, 0); // ready=0 | delay=period=time | enable=1
    os.addTask(pNewFunction, ptrAnytask, 20, 1);
    os.addTask(pInputData, ptrAnytask, 5, 2);

    cout << "FLAG TEST: Init Run_RTC_Scheduler" << endl;

    //os.Request_Task_Run(0); // set ready=1
    //os.Request_Task_Run(1);
    //os.Request_Task_Run(2);

    os.Run_RTC_Scheduler();

    cout << "FLAG TEST: After Run_RTC_Scheduler" << endl;

    return 0;
}
*/
