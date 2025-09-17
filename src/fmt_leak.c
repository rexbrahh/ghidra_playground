// fmt_leak.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_secret(void) {
  char secret[] = "FLAG{fmt_leak}";
  printf("secret in memory: %s\n", secret);
}

int main(int argc, char **argv) {
  char buf[128];
  if (argc < 2) {
    puts("usage: fmt_leak <input>");
    return 1;
  }
  strncpy(buf, argv[1], sizeof(buf) - 1);
  buf[127] = 0;
  // unsafe on purpose
  printf(buf);
  puts("");
  print_secret();
  return 0;
}
