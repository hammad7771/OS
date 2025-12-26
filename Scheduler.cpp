// #include "Scheduler.h"
// #include <iostream>

// using namespace std;

// void Scheduler::addProcess(Process* p) {
//     readyQueue.push(p);
// }

// void Scheduler::runFCFS() {
//     while (!readyQueue.empty()) {
//         Process* p = readyQueue.front();
//         readyQueue.pop();
//         cout << "Running Process PID: " << p->pid << endl;
//     }
// }

// void Scheduler::runRoundRobin(int quantum) {
//     cout << "Round Robin with quantum " << quantum << endl;
// }



#include "Scheduler.h"
#include <iostream>
#include <algorithm>

using namespace std;

// void Scheduler::addProcess(Process* p) {
//     readyQueue.push(p);
// }

void Scheduler::addProcess(Process* p) {
    allProcesses.push_back(p);
    readyQueue.push(p);
}


void Scheduler::reloadReadyQueue() {
    readyQueue = queue<Process*>();
    for (auto p : allProcesses) {
        readyQueue.push(p);
    }
}


//
// FCFS
//
void Scheduler::runFCFS() {
    cout << "\n🚀 Running FCFS Scheduling\n";

    int currentTime = 0;

    while (!readyQueue.empty()) {
        Process* p = readyQueue.front();
        readyQueue.pop();

        p->waitingTime = currentTime - p->arrivalTime;
        if (p->waitingTime < 0) p->waitingTime = 0;

        currentTime += p->burstTime;

        p->turnaroundTime = currentTime - p->arrivalTime;

        cout << " PID " << p->pid
             << " | Waiting: " << p->waitingTime
             << " | Turnaround: " << p->turnaroundTime << endl;
    }
    cout<<"Exiting from FCFS Scheduling"<<endl;
    cout<<"-----------------------------------"<<endl;
}

//
// ROUND ROBIN
//
void Scheduler::runRoundRobin(int quantum) {
    cout << "\n⏱️ Running Round Robin | Quantum = " << quantum << endl;

    queue<Process*> temp = readyQueue;
    int currentTime = 0;

    while (!temp.empty()) {
        Process* p = temp.front();
        temp.pop();

        if (p->remainingTime > quantum) {
            cout << " 🔁 Process " << p->pid << " executed for " << quantum << endl;
            p->remainingTime -= quantum;
            currentTime += quantum;
            temp.push(p);
        } else {
            currentTime += p->remainingTime;
            cout << " ✅ Process " << p->pid << " finished" << endl;
            p->remainingTime = 0;
        }
    }
    cout<<"Exiting from Round Robin Scheduling"<<endl;
    cout<<"-----------------------------------"<<endl;
}

//
// PRIORITY SCHEDULING
//
void Scheduler::runPriority() {
    cout << "\n🏅 Running Priority Scheduling\n";

    vector<Process*> processes;

    while (!readyQueue.empty()) {
        processes.push_back(readyQueue.front());
        readyQueue.pop();
    }

    sort(processes.begin(), processes.end(),
         [](Process* a, Process* b) { return a->priority < b->priority; });

    for (auto p : processes) {
        cout << " PID " << p->pid << " | Priority " << p->priority << endl;
    }
    cout<<"Exiting from Priority Scheduling"<<endl;
    cout<<"-----------------------------------"<<endl;
}

//
// SHORTEST JOB FIRST
//
void Scheduler::runSJF() {
    cout << "\n⚡ Running Shortest Job First (SJF)\n";

    vector<Process*> processes;

    while (!readyQueue.empty()) {
        processes.push_back(readyQueue.front());
        readyQueue.pop();
    }

    sort(processes.begin(), processes.end(),
         [](Process* a, Process* b) { return a->burstTime < b->burstTime; });

    for (auto p : processes) {
        cout << " PID " << p->pid << " | Burst " << p->burstTime << endl;
    }
    cout<<"Exiting from SJF"<<endl;
    cout<<"-----------------------------------"<<endl;
}

