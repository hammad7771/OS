// #include "MemoryManager.h"

// MemoryManager::MemoryManager(int size) {
//     totalMemory = size;
//     usedMemory = 0;
// }

// bool MemoryManager::allocate(int size) {
//     if (usedMemory + size <= totalMemory) {
//         usedMemory += size;
//         return true;
//     }
//     return false;
// }

// void MemoryManager::deallocate(int size) {
//     if (size <= 0) return;  // ignore invalid values

//     if (size > usedMemory) {
//         // Prevent underflow
//         usedMemory = 0;
//     } else {
//         usedMemory -= size;
//     }
// }


#include "MemoryManager.h"
#include <iostream>
using namespace std;

MemoryManager::MemoryManager(int size) {
    totalMemory = size;
    usedMemory = 0;
}

bool MemoryManager::allocate(int size) {
    if (usedMemory + size <= totalMemory) {
        usedMemory += size;
        return true;
    }
    return false;
}

void MemoryManager::deallocate(int size) {
    if (size <= 0) return;

    if (size >= usedMemory)
        usedMemory = 0;
    else
        usedMemory -= size;
}

void MemoryManager::display() {
    cout << "\n📦 Memory Status\n";
    cout << "---------------------------\n";
    cout << " Total Memory : " << totalMemory << endl;
    cout << " Used Memory  : " << usedMemory << endl;
    cout << " Free Memory  : " << totalMemory - usedMemory << endl;
}
