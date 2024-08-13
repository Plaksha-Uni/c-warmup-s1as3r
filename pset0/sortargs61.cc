#include <cstddef>
#include <cstdio>
#include <cstring>

void insertion_sort(char *arr[], size_t len) {
  for (size_t i = 1; i < len; i++) {
    size_t j = i;
    while (j > 0 && strcmp(arr[j - 1], arr[j]) > 0) {
      char *temp = arr[j - 1];
      arr[j - 1] = arr[j];
      arr[j] = temp;
      j--;
    }
  }
}

int main(int argc, char *argv[]) {
  insertion_sort(&argv[1], (size_t)argc - 1);
  for (int i = 1; i < argc; i++) {
    fprintf(stdout, "%s\n", argv[i]);
  }
  return 0;
}
