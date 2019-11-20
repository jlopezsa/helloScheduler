#include <iostream>
#include <time.h>

using namespace std;

#include "Escalonador.cpp"

//-----------------------------------------------------
void newFunction()
{
    cout << "TASK PRI 1: New message for testing" << endl;
}
//-----------------------------------------------------
void inputData()
{
    int value;
    cout << "TASK PRI 2: Input integer value: " << endl;
    
    //newObj.ptrEsc = new Escalonador();
    //newObj.ptrEsc->Disable_Task(2);
    //os.Run_RTC_Scheduler();

    //cin >> value;
    
    /*while(!(cin >> value))
    {
        cout << " ???? " << endl;
    }*/
    
}
//-----------------------------------------------------
void hello()
{
    cout << "TASK PRI 0: Hello scheduler" << endl;

}
//-----------------------------------------------------

int main()
{
    Escalonador os;
    os.setPtrEsc(&os);
    
    os.init_Task_Timers();

    os.addTask(hello, 30, 0); // ready=0 | delay=period=time | enable=1
    os.addTask(newFunction, 20, 1);
    os.addTask(inputData, 10, 2);

    cout << "FLAG TEST: Init Run_RTC_Scheduler" << endl;

    //os.Request_Task_Run(0); // set ready=1
    //os.Request_Task_Run(1);
    //os.Request_Task_Run(2);

    os.Run_RTC_Scheduler();


    cout << "FLAG TEST: After Run_RTC_Scheduler" << endl;

    return 0;
}