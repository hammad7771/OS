#ifndef PROCESS_H
#define PROCESS_H

class Process {
public:
    int pid;
    int burstTime;
    int memoryRequired;

    Process(int id, int bt, int mem);
};

#endif
