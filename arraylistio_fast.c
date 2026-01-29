#include "arraylistio_core.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static size_t max(size_t a, size_t b) { return a > b ? a : b; }

// expand = {0, 1}
int fast_list_resize(ArrayList *list, int expand) {
  int new_capacity;
  int *new_contents = NULL;
  if (expand) {
    new_capacity = list->capacity * 2;
  } else {
    new_capacity = list->capacity / 2;
  }
  // Set minimum capacity.
  new_capacity = max(new_capacity, MIN_CAPACITY);

  new_contents =
      realloc(list->contents, new_capacity * sizeof(*list->contents));
  if (new_contents == NULL) {
    printf("realloc error: new_list is null\n");
    return 1;
  }
  list->contents = new_contents;
  list->capacity = new_capacity;
  return 0;
}

int fast_list_append(ArrayList *list, int elem) {
  int result_resize;
  // resize when list is full
  if (list->occupied == list->capacity) {
    result_resize = fast_list_resize(list, 1);
    if (result_resize != 0) {
      return result_resize;
    }
  }
  // insert new element at end of list
  // assume list is filled contiguously
  list->contents[list->occupied] = elem;
  list->occupied++;
  return 0;
}

// Use C-style function signature allowing proper error handling.
// Return value describes failure/success
// Data gets send back via *out
int fast_list_remove(ArrayList *list, size_t index, int *out) {
  int result_resize;
  if (index >= list->occupied) {
    printf("list_remove error: index out of bounds.");
    return 1;
  }
  if (out == NULL) {
    printf("list_remove error: got NULL as *out.");
    return 2;
  }
  // write removed value
  *out = list->contents[index];
  // Plug the hole
  memmove(list->contents + index, list->contents + index + 1,
          (list->occupied - index - 1) * sizeof(*list->contents));
  list->occupied--;
  // resize when list is half empty
  if (list->capacity > MIN_CAPACITY && list->occupied < list->capacity / 2) {
    result_resize = fast_list_resize(list, 0);
    if (result_resize != 0) {
      return result_resize;
    }
  }
  return 0;
}
