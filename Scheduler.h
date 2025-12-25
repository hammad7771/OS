#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <queue>
#include "Process.h"

class Scheduler {
private:
    std::queue<Process*> readyQueue;

public:
    void addProcess(Process* p);
    void runFCFS();
    void runRoundRobin(int quantum);
};

#endif
