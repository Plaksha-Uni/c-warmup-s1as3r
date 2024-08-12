#include <cstdint>
#include <cstdio>
#include <cctype>


int main() {
  uint32_t bytes = 0;
  uint32_t words = 0;
  uint32_t lines = 0;

  bool last_was_space = true;
  bool curr_is_space = false;
  bool last_was_newline = false;

  char c;
  while (true) {
    c = fgetc(stdin);
    if (c == EOF) {
      if (!last_was_newline && bytes > 0) {
        lines++;
      }
      break;
    }

    bytes++;

    curr_is_space = isspace(c);
    if (last_was_space && !curr_is_space) {
      words++;
    }
    last_was_space = curr_is_space;

    last_was_newline = c == '\n';
    if (last_was_newline) {
      lines++;
    }
  }

  fprintf(stdout, "\t%u\t%u\t%u\n", lines, words, bytes);
}
