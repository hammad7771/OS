// #include "Process.h"

// Process::Process(int id, int bt, int mem) {
//     pid = id;
//     burstTime = bt;
//     memoryRequired = mem;
// }

#include "Process.h"

Process::Process(int id, int bt, int mem, int at, int pr) {
    pid = id;
    burstTime = bt;
    remainingTime = bt;
    memoryRequired = mem;
    arrivalTime = at;
    priority = pr;

    waitingTime = 0;
    turnaroundTime = 0;
}
