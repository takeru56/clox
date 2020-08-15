#include <stdlib.h>

#include "memory.h"

void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
  if (newSize == 0) {
    free(pointer);
    return NULL;
  }

  // 後ろの要素が空いてなかった場合，新しいブロックをallocしそこにコピーし，新しいポインタを返す
  // allocに失敗した場合NULLを返す
  void* result = realloc(pointer, newSize);
  if (result == NULL) exit(1);
  return result;
}
