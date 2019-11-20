#ifndef ESCALONADOR
#define ESCALONADOR

#include <string>
using namespace std;

#include "Timer.h"

#define MAX_TASKS 3 // nr. máximo de tarefas

// Define estrutura com as informações da Task Control Block (TCB)
struct task_t
{
    void (*task)(void); // ponteiro para uma função
    int ready;          // se 1: pronto para executar, se 0: não pronto para executar
    int delay;
    int period;
    int enabled; // se 1: tarefa ativa, se 0: não ativa
};

// Define a classe
class Escalonador
{
private:
    task_t GBL_task_table[MAX_TASKS]; // tabela global de tarefas
public:
    Escalonador();
    ~Escalonador();
    void init_Task_Timers(void); // inicializa todas as tarefas em 0
    int addTask(void (*task)(void), int time, int priority);
    //void removeTask(void (*task)(void));
    void Enable_Task(int task_number);
    void Disable_Task(int task_number);
    void Run_RTC_Scheduler(/*TecladoPc* pT*/);
    void tick_timer_intr(void);
    void Request_Task_Run(int task_number);
    void setPtrEsc(Escalonador *newPtr);
    Escalonador *getPtrEsc();
    Timer objTimer;
    Escalonador *ptrEsc;
};

#endif // ESCALONADOR