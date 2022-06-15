#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i;
  printf("argc: %d\n", argc);
  for (i = 0; i < argc; i++) {
    printf("argv[%d]: %s\n", i, argv[i]);
  }

  FILE *code = fopen(argv[1], "r");
  if (code == NULL) {
    printf("File not found!");
    exit(1);
  }

  FILE *out = fopen("out.c", "w");
  if (out == NULL) {
    printf("Output file could not be created!");
    exit(1);
  }

  char c = fgetc(code);
  while(c != EOF) {
    switch (c) {
      case '+': fputs("cell[ptr]++;", out);
      break;
      case '-': fputs("cell[ptr]--;", out);
      break;
      case '>': fputs("ptr++;", out);
      break;
      case '<': fputs("ptr--;", out);
      break;
      case '.': fputs("putchar(cell[ptr]);", out);
      break;
      case ',': fputs("cell[ptr] = getchar();", out);
      break;
      case '[': fputs("while(cell[ptr]) {", out);
      break;
      case ']': fputs("}", out);
      break;
      default:
      break;
    }
    c = fgetc(code);
  }
  fclose(out);
  fclose(code);

  return 0;
}
