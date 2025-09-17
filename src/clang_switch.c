// clang_switch.c
#include <stdio.h>
#include <stdlib.h>

static void prize(void) { puts("CLANG-PRIZE"); }

int main(int argc, char **argv) {
  int v = argc > 1 ? atoi(argv[1]) : 42;
  int sel = ((v * 9) >> 2) & 3;
  switch (sel) {
  case 0:
    puts("zero");
    break;
  case 1:
    puts("one");
    break;
  case 2:
    puts("two");
    break;
  case 3:
    prize();
    break;
  }
  return 0;
}
