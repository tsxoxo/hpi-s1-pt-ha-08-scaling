#include <stdlib.h>
#include <stdio.h>
#include <time.h>
// TODO: includes


int main(void)
{
    int mode;
    printf("Choose fast (0) or basic (1):\n");
    scanf("%d", &mode);

    ArrayList *list = make_list();
    if (list == NULL)
    {
        return 1;
    }

    int BIG_NUMBER = 100000000;

    // How to measure performance in C? https://stackoverflow.com/a/5249129/10917436
    clock_t tic = clock();
    for (int i = 0; i < BIG_NUMBER; i++)
    {
        if (mode == 1)
        {
            list_append(list, i);
        }
        else
        {
            fast_list_append(list, i);
        }
    }
    clock_t toc = clock();
    printf("Elapsed appending: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    // sanity check - prints huge list
    // int max_iter = list->occupied == 0 ? list->capacity : list->occupied;
    // for (int i = 0; i < max_iter; i++)
    // {
    //     printf("list[%d] = %d\n", i, list_get(list, i));
    // }

    tic = clock();
    for (int i = BIG_NUMBER - 1; i >= BIG_NUMBER / 2; i--)
    {
        if (mode == 1)
        {
            list_remove(list, i);
        }
        else
        {
            fast_list_remove(list, i);
        }
    }
    toc = clock();
    printf("Elapsed removing: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    // sanity check - prints huge list
    // int max_iter2 = list->occupied == 0 ? list->capacity : list->occupied;
    // for (int i = 0; i < max_iter2; i++)
    // {
    //     printf("list[%d] = %d\n", i, list_get(list, i));
    // }

    list_free(list);

    return 0;
}