
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

bool is_ascii(const char str[], size_t size)
{
    if (size == 0)
        return false;
    int i = 0;
    while (i < size) {
      if ((str[i] & 0x5F) < 65 || (str[i] & 0x5F) > 90)
        return false;
      i++;
    }
    return true;
}

void main() {
  char t[] = {"sdsdsdsdrhjk"};
  char s[] = {"Abds@djilajdl~!]"};
  if (is_ascii(t, strlen(t)))
    printf("TRUE\n");
  if (is_ascii(s, strlen(s)))
    printf("TRUE\n");
}
