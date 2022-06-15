#include <stdlib.h>
#include <stdio.h>

char *cell;
int ptr;
int main() {
  cell = malloc(40000 * sizeof(char));
  ptr = 0;
  #include "out.c"
}
