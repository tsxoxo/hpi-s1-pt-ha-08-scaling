#include <stdlib.h>
#include <stdio.h>
// TODO: includes

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