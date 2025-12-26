#include <iostream>
#include <vector>

#include "Process.h"
#include "Scheduler.h"
#include "MemoryManager.h"

using namespace std;


int main() {

    MemoryManager mem(200);
    Scheduler sched;

    int choice;

    while (true) {

        cout << "\n================ OS SCHEDULER MENU ================\n";
        cout << "1. Add processes\n";
        cout << "2. Run FCFS\n";
        cout << "3. Run Round Robin\n";
        cout << "4. Run Priority Scheduling\n";
        cout << "5. Run SJF\n";
        cout << "6. Show Memory Status\n";
        cout << "0. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "\nExiting... Goodbye!\n";
            break;
        }

        if (choice == 1) {

            int n;
            cout << "\nHow many processes do you want to add? ";
            cin >> n;

            for (int i = 0; i < n; i++) {

                int bt, memReq, at, pr;

                cout << "\n--- Enter details for Process " << i + 1 << " ---\n";

                cout << "Burst Time: ";
                cin >> bt;

                cout << "Memory Required: ";
                cin >> memReq;

                cout << "Arrival Time: ";
                cin >> at;

                cout << "Priority (lower value means higher priority): ";
                cin >> pr;

                if (!mem.allocate(memReq)) {
                    cout << "Process rejected: Not enough memory\n";
                    continue;
                }

                Process* p = new Process(i + 1, bt, memReq, at, pr);
                sched.addProcess(p);

                cout << "Process added successfully\n";
            }
        }

        else if (choice == 2) {
            cout << "\nRunning FCFS Scheduling...\n";
            sched.reloadReadyQueue();
            sched.runFCFS();
        }

        else if (choice == 3) {
            int q;
            cout << "Enter time quantum: ";
            cin >> q;
            cout << "\nRunning Round Robin...\n";
            sched.reloadReadyQueue();
            sched.runRoundRobin(q);
        }

        else if (choice == 4) {
            cout << "\nRunning Priority Scheduling...\n";
            sched.reloadReadyQueue();
            sched.runPriority();
        }

        else if (choice == 5) {
            cout << "\nRunning Shortest Job First...\n";
            sched.reloadReadyQueue();
            sched.runSJF();
        }

        else if (choice == 6) {
            mem.display();
        }

        else {
            cout << "Invalid Choice\n";
        }

        cout << "\nPress Enter to return to menu...";
        cin.ignore();
        cin.get();
    }

    return 0;
}
