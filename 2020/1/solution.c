#include <stdio.h>
#include <stdlib.h>
int main() {
  int i, used = 0, allocated = 32;
  int *entries = malloc(sizeof(*entries) * allocated);
  for (;;) {
    if (1 != scanf(" %i ", &entries[used++])) {
      fputs("no pair found\n", stderr);
      return 1;
    }
    if (used >= allocated) {
      allocated *= 2;
      entries = realloc(entries, sizeof(*entries) * allocated);
    }
    for (i = used - 1; i >= 0; --i) {
      if (entries[i] + entries[used - 1] == 2020) {
        printf("%i\n", entries[i] * entries[used - 1]);
        return 0;
      }
    }
  }
}
