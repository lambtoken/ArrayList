#include <stdio.h>
#include "ArrayList.h"

int main() {

    struct ArrayList* list = NewArrayList();

    for(int i = 0; i < 22000; i++) {
        list->push(list, i);
    }

    printf("15th element: %d\n", list->get(list, 15));
    printf("Size of the list: %d\n", list->size);
    printf("Capacity of the list: %d\n", list->capacity);

    FreeArrayList(list);

    return 0;
}