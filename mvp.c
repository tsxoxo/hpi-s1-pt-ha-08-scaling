#include "arraylistio_basic.h"
#include "arraylistio_core.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  ArrayList *list = make_list();
  // QUESTION: I changed the func signature fro teacher's. is there a way to
  // avoid this dummy var?
  int _dummy;
  if (list == NULL) {
    return 1;
  }

  for (int i = 0; i < 10; i++) {
    list_append(list, i);
  }
  list_remove(list, 4, &_dummy);
  list_remove(list, 4, &_dummy);
  list_append(list, 1337);
  for (int i = 0; i < list->capacity; i++) {
    printf("list[%d] = %d\n", i, list_get(list, i));
  }
  list_free(list);
  return 0;
}
