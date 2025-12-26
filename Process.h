// #ifndef PROCESS_H
// #define PROCESS_H

// class Process {
// public:
//     int pid;
//     int burstTime;
//     int memoryRequired;

//     Process(int id, int bt, int mem);
// };

// #endif


#ifndef PROCESS_H
#define PROCESS_H

class Process {
public:
    int pid;
    int burstTime;
    int remainingTime;
    int memoryRequired;
    int arrivalTime;
    int priority;

    int waitingTime;
    int turnaroundTime;

    Process(int id, int bt, int mem, int at, int pr);
};

#endif
