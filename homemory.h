#ifndef HOMEMORY_H
#define HOMEMORY_H

#include <stdio.h>
#include <stdlib.h>

struct Memory {
    int id;
    void* m;
    struct Memory* next;
};

struct MemoryReturn {
    int id;
    void* m;
};

struct Memory* memory_init();
struct MemoryReturn memory_create(struct Memory* node, int memory_size);
struct MemoryReturn memory_realloc(struct Memory* node, int mem_id, int new_size);
void memory_free(struct Memory* node, int mem_id);
void memory_free_all(struct Memory* node);
void memory_show_all(struct Memory* node);

#endif
