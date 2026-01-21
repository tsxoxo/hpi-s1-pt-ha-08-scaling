#ifndef ARRAYLISTIO_FAST
#define ARRAYLISTIO_FAST

#include "arraylistio_core.h"

int fast_list_resize(ArrayList *list, int amount);
int fast_list_append(ArrayList *list, int elem);
int fast_list_remove(ArrayList *list, size_t index, int *out);
void fast_list_free(ArrayList *list);

#endif
