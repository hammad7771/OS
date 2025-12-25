// main.cpp
#include <iostream>
#include <vector>

#include "Process.h"
#include "Scheduler.h"
#include "MemoryManager.h"

using namespace std;

int main() {
    Scheduler scheduler;
    MemoryManager memory(1024); // 1024 MB memory
    std::vector<Process*> processTable;

    int pidCounter = 1;
    int choice;

    do {
        std::cout << "\n1. Create Process\n2. Run FCFS\n3. Run Round Robin\n4. Exit\n";
        std::cin >> choice;

        if (choice == 1) {
            int bt, mem;
            std::cout << "Enter Burst Time & Memory: ";
            std::cin >> bt >> mem;

            if (memory.allocate(mem)) {
                Process* p = new Process(pidCounter++, bt, mem);
                scheduler.addProcess(p);
                processTable.push_back(p);
                std::cout << "Process Created\n";
            } else {
                std::cout << "Not enough memory!\n";
            }
        }

        else if (choice == 2) {
            scheduler.runFCFS();
        }

        else if (choice == 3) {
            int q;
            std::cout << "Enter Time Quantum: ";
            std::cin >> q;
            scheduler.runRoundRobin(q);
        }

    } while (choice != 4);

    return 0;
}
