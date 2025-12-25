#include "MemoryManager.h"

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
    usedMemory -= size;
}
