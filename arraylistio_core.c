#include <stdlib.h>
#include <stdio.h>
#include "arraylistio_core.h"

ArrayList *make_list()
{
    int *contents = malloc(0);
    if (contents == NULL)
    {
        printf("malloc error: contents is null\n");
        return NULL;
    }
    ArrayList *list = malloc(sizeof(ArrayList));
    if (list == NULL)
    {
        printf("malloc error: list is null\n");
        return NULL;
    }
    list->contents = contents;
    list->capacity = 0;
    list->occupied = 0; // this will become handy later
    return list;
}

// Get the element at `index`. This is unsafe as it does not check if the index is in bounds.
int list_get(ArrayList *list, size_t index)
{
    return list->contents[index];
}