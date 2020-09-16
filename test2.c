#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint64_t hexchar2val(char *in) {
  int str_point = 0;
  uint64_t value = 0;
  if (*in == '0' && *(in + 1) == 'x')
    str_point = 2;
  for (int i = str_point, j = strlen(in) - str_point - 1; i < strlen(in);
       i++, j--) {
    uint8_t letter = *(in + i) & 0x40;
    uint8_t shift = (letter >> 3) | (letter >> 6);
    value += pow(16, j) * (int)((*(in + i) + shift) & 0xf);
  }
  return value;
}

void main()
{
  printf("%ld\n", hexchar2val("f"));
  printf("%ld\n", hexchar2val("F"));
  printf("%ld\n", hexchar2val("0xFF"));
  printf("%ld\n", hexchar2val("0xCAFEBABE"));
  printf("%ld\n", hexchar2val("0x8BADFOOD"));
}
