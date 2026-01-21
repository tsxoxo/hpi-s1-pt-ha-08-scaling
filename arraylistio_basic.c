#include "arraylistio_core.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// NOTE: what do we do when list shrinks to 0?
int list_resize(ArrayList *list, int amount) {
  int new_capacity = list->capacity + amount;
  if (new_capacity < 0) {
    printf("list_resize error: cannot resize to negative capacity.");
    return 2;
  }
  int *new_contents =
      realloc(list->contents, new_capacity * sizeof(*list->contents));
  if (new_contents == NULL) {
    printf("realloc error: new_list is null\n");
    return 1;
  }
  list->contents = new_contents;
  list->capacity = new_capacity;
  return 0;
}

int list_append(ArrayList *list, int elem) {
  int result_resize = list_resize(list, 1);
  // make space for new element
  if (result_resize != 0) {
    return result_resize;
  }
  // last = new element
  list->contents[list->capacity - 1] = elem;
  return 0;
}

int list_remove(ArrayList *list, size_t index, int *out) {
  int resize_result;
  if (index >= list->capacity) {
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
  memmove(&list->contents[index], &list->contents[index + 1],
          (list->capacity - index - 1) * sizeof(*list->contents));
  resize_result = list_resize(list, -1);
  if (resize_result != 0) {
    return resize_result;
  }
  return 0;
}

void list_free(ArrayList *list) {
  if (list) {
    free(list->contents);
    free(list);
  }
}
