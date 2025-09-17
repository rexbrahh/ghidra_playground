// xor_packer.c
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static uint8_t packed[] = {0x10, 0x27, 0x31, 0x26, 0x5a,
                           0x78, 0x24, 0x21, 0x00}; // "UNPACKED\n\0" XOR 0x41

void run_unpacked(void) {
  // placeholder -- in "real" packer you'd jump here after unpack
  puts("Ran unpacked payload!");
}

int main(void) {
  size_t n = sizeof(packed);
  uint8_t key = 0x41;
  uint8_t *buf = malloc(n + 1);
  for (size_t i = 0; i < n; i++)
    buf[i] = packed[i] ^ key;
  buf[n] = 0;
  printf("In-memory string: %s", buf);
  run_unpacked();
  free(buf);
  return 0;
}
