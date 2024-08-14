#include <cassert>
#include <cstddef>
#include <cstdio>
#include <cstring>

size_t mystrlen(const char *s) {
  size_t len = 0;
  while (*(s + len) != '\0') {
    len++;
  }
  return len;
}

bool strcmp_upto(const char *s1, const char *s2, size_t len) {
  if (mystrlen(s1) < len) {
    return false;
  }

  size_t count = 0;
  for (char *c1 = (char *)s1, *c2 = (char *)s2; count < len;
       count++, c1++, c2++) {
    if (*c1 != *c2) {
      return false;
    }
  }

  return true;
}

char *mystrstr(const char *s1, const char *s2) {
  size_t len = mystrlen(s2);
  if (len == 0) {
    return (char *)s1;
  }

  for (char *c = (char *)s1; *c != '\0'; c++) {
    if (*c == *s2 && strcmp_upto(c, s2, len)) {
      return c;
    }
  }
  return nullptr;
}

int main(int argc, char *argv[]) {
  assert(argc == 3);
  printf("strstr(\"%s\", \"%s\") = %p\n", argv[1], argv[2],
         strstr(argv[1], argv[2]));
  printf("mystrstr(\"%s\", \"%s\") = %p\n", argv[1], argv[2],
         mystrstr(argv[1], argv[2]));
  assert(strstr(argv[1], argv[2]) == mystrstr(argv[1], argv[2]));
}
