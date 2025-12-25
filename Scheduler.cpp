#include "Scheduler.h"
#include <iostream>

using namespace std;

void Scheduler::addProcess(Process* p) {
    readyQueue.push(p);
}

void Scheduler::runFCFS() {
    while (!readyQueue.empty()) {
        Process* p = readyQueue.front();
        readyQueue.pop();
        cout << "Running Process PID: " << p->pid << endl;
    }
}

void Scheduler::runRoundRobin(int quantum) {
    cout << "Round Robin with quantum " << quantum << endl;
}
