#include <cstdio>

int main() {
  int bytes = 0;
  while (fgetc(stdin) != EOF) {
    bytes++;
  }

  fprintf(stdout, "\t%d\n", bytes);
}
