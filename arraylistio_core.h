// this is new! we should always add a guard to a header file to prevent errors
// when the header file is included multiple times `ARRAYLISTIO_CORE` can be a
// random name but a best practice is to include the project name and/or file
// name to avoid collisions
#ifndef ARRAYLISTIO_CORE
#define ARRAYLISTIO_CORE

#include <stddef.h>

typedef struct ArrayList {
  int *contents;
  int capacity;
  int occupied; // this might become handy later, maybe we will allocate more
                // capacity than we need for some reason
} ArrayList;

ArrayList *make_list();

// QUESTION: Why does my LSP complain 'unknown type name size_t'?
int list_get(ArrayList *list, size_t index);

#endif
