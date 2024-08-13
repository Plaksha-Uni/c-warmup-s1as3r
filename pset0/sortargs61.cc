#include <algorithm>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

[[maybe_unused]] void insertion_sort(char *arr[], size_t len) {
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

std::vector<std::string> stdlib_sort(char *arr[], size_t len) {
  std::vector<std::string> vec(arr, arr + len);

  std::sort(vec.begin(), vec.end());

  return vec;
}

int main(int argc, char *argv[]) {
  std::vector<std::string> vec = stdlib_sort(&argv[1], argc - 1);
  for (std::string& elem : vec) {
    std::cout << elem << "\n";
  }
  return 0;
}
