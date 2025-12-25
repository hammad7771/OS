#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

class MemoryManager {
private:
    int totalMemory;
    int usedMemory;

public:
    MemoryManager(int size);
    bool allocate(int size);
    void deallocate(int size);
};

#endif
