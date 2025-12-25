#include "Process.h"

Process::Process(int id, int bt, int mem) {
    pid = id;
    burstTime = bt;
    memoryRequired = mem;
}
