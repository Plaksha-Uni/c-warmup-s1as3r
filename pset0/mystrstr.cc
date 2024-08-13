#include <cassert>
#include <cstddef>
#include <cstdio>
#include <cstring>

size_t mystrlen(const char* s) {
  size_t len = 0;
  while (s[len] != '\0') {
    len++;
  }
  return len;
}

bool strcmp_upto(const char* s1, const char* s2, size_t len) {
  if (mystrlen(s1) < len) {
    return false;
  }

  for (size_t i = 0; i < len; i++) {
    if (s1[i] != s2[i]) {
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

  for (size_t i = 0; s1[i] != '\0'; i++) {
    if (s1[i] == s2[0] && strcmp_upto(&s1[i], s2, len)) {
        return (char *)&s1[i];
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
