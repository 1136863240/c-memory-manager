#include "homemory.h"

struct Memory* memory_init() {
    struct Memory* node = malloc(sizeof(struct Memory));
    node->id = 0;
    node->m = NULL;
    node->next= NULL;
    return node;
}

struct MemoryReturn memory_create(struct Memory* node, int memory_size) {
    struct Memory* temp = node;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    struct Memory* n = malloc(sizeof(struct Memory));
    n->id = temp->id + 1;
    n->m = malloc(memory_size);
    n->next = NULL;
    temp->next = n;

    struct MemoryReturn ret;
    ret.id = n->id;
    ret.m = n->m;
    return ret;
}

struct MemoryReturn memory_realloc(struct Memory* node, int mem_id, int new_size) {
    struct Memory* temp = node;
    while (temp->next != NULL && temp->id != mem_id) {
        temp = temp->next;
    }
    if (temp->id != mem_id) {
        struct MemoryReturn ret;
        ret.id = -1;
        ret.m = NULL;
        return ret;
    }
    else {
        temp->m = realloc(temp->m, new_size);
        struct MemoryReturn ret;
        ret.id = temp->id;
        ret.m = temp->m;
        return ret;
    }
}

void memory_free(struct Memory* node, int mem_id) {
    struct Memory* prev = NULL;
    struct Memory* n = node;
    while (n->next != NULL && n->id != mem_id) {
        prev = n;
        n = n->next;
    }
    if (n == NULL) {
        return;
    }
    else {
        prev->next = n->next;
        free(n->m);
        free(n);
    }
}

void memory_free_all(struct Memory* node) {
    struct Memory* n = node;
    while (n != NULL) {
        struct Memory* temp = n;
        n = n->next;
        if (temp->m != NULL) {
            free(temp->m);
        }
        free(temp);
    }
}

void memory_show_all(struct Memory* node) {
    struct Memory* n = node;
    while (n != NULL) {
        printf("%d %s\n", n->id, (char*)n->m);
        n = n->next;
    }
}
