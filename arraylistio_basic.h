#ifndef ARRAYLISTIO_BASIC
#define ARRAYLISTIO_BASIC

#include "arraylistio_core.h"

int list_resize(ArrayList *list, int amount);
int list_append(ArrayList *list, int elem);
int list_remove(ArrayList *list, size_t index, int *out);
void list_free(ArrayList *list);

#endif
