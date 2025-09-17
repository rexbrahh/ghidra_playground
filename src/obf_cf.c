// obf_cf.c
#include <stdint.h>
#include <stdio.h>

int opaque(int x) {
  // intentionally weird math so decompiler branches look odd
  uint64_t a = (uint64_t)x * 0x9e3779b97f4a7c15ULL;
  return (int)((a >> 32) ^ (a & 0xffffffff));
}

void secret(void) { puts("SECRET: CF-WIN"); }

int main(int argc, char **argv) {
  int v = argc > 1 ? atoi(argv[1]) : 0;
  int ov = opaque(v);
  if (((ov ^ v) & 0x7) == 5) {
    secret();
  } else {
    puts("nope");
  }
  return 0;
}
