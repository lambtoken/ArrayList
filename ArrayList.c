#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

struct ArrayList* NewArrayList() {
    struct ArrayList* instance = (struct ArrayList*)malloc(sizeof(struct ArrayList));
    
    if (instance == NULL) {
        return NULL;
    }

    instance->capacity = DEFAULT_SIZE;
    instance->list = (int*)malloc(instance->capacity * sizeof(int));
    instance->get = get;
    instance->push = push;
    instance->pop = pop;
    instance->size = 0;

    return instance;
}

void FreeArrayList(struct ArrayList* al) {
    free(al->list);
    free(al);
}

int get(struct ArrayList* al, int index) {
    return al->list[index];
}

int pop(struct ArrayList* al) {
    if (al->size > 0) {
        int i = al->size;
        int num = al->list[i];
        al->list[i] = 0;
        al->size -= 1;
        return num;
    }

    return 0;
}

int push(struct ArrayList* al, int number) {
    if (al->size >= al->capacity) {
        extend(al);
    }
    
    al->list[al->size] = number;
    al->size ++;
    return al->size;
}

void extend(struct ArrayList* al) {
    int new_capacity = al->capacity * 2;
    al->capacity = new_capacity;

    al->list = realloc(al->list, new_capacity * sizeof(int));
}