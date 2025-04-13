#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#define DEFAULT_SIZE 10

struct ArrayList {
    int* list;
    int size;
    int capacity;
    int (*push)(struct ArrayList* al, int num); // returns index
    int (*pop)(struct ArrayList* al); // returns element
    int (*get)(struct ArrayList* al, int index); // returns element
};

struct ArrayList* NewArrayList();
void FreeArrayList(struct ArrayList* al);
int get(struct ArrayList* al, int index);
int push(struct ArrayList* al, int number);
int pop(struct ArrayList* al);
void extend(struct ArrayList* al);

#endif