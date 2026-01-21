#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int *contents;
    int capacity;
} ArrayList;

// Creates an empty list
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
    return list;
}

void list_resize(ArrayList *list, int amount)
{
    list->capacity += amount;
    list->contents = realloc(list->contents, list->capacity * sizeof(int));
}
void list_append(ArrayList *list, int elem)
{
    list_resize(list, 1);
    list->contents[list->capacity - 1] = elem;
}
int list_remove(ArrayList *list, size_t index)
{
    int return_ele = list->contents[index];
    for (int idx = index; idx < list->capacity - 1; idx++)
    {
        list->contents[idx] = list->contents[idx + 1];
    }
    list_resize(list, -1);
    return return_ele;
}

void list_free(ArrayList *list)
{
    free(list->contents);
    free(list);
}

// Get the element at `index`. This is unsafe as it does not check if the index is in bounds.
int list_get(ArrayList *list, size_t index)
{
    return list->contents[index];
}

int main(void)
{
    ArrayList *list = make_list();
    if (list == NULL)
    {
        return 1;
    }

    for (int i = 0; i < 10; i++)
    {
        list_append(list, i);
    }
    list_remove(list, 4);
    list_remove(list, 4);
    list_append(list, 1337);
    for (int i = 0; i < list->capacity; i++)
    {
        printf("list[%d] = %d\n", i, list_get(list, i));
    }
    list_free(list);
    return 0;
}