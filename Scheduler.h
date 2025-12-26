#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <queue>
#include <vector>

#include "Process.h"

class Scheduler {
private:
    std::queue<Process*> readyQueue;
    std::vector<Process*> allProcesses;

public:
    void addProcess(Process* p);
    void reloadReadyQueue();

    void runFCFS();
    void runRoundRobin(int quantum);
    void runPriority();
    void runSJF();
};

#endif
