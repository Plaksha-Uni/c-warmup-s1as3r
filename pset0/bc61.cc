#include <cstdint>
#include <cstdio>

int main() {
  uint32_t bytes = 0;
  while (fgetc(stdin) != EOF) {
    bytes++;
  }

  fprintf(stdout, "\t%u\n", bytes);
}
