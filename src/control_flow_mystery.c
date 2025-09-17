// controlflow_mystery.c
#include <stdio.h>
#include <stdlib.h>

int branch_one(int x) { return x + 2; }
int branch_two(int x) { return x * 3; }
int branch_three(int x) { return x - 7; }
void print_prize(void) { puts("Congrats! Here is the prize: GHIDRA-PLAY"); }

int main(int argc, char **argv) {
  if (argc < 2) {
    puts("Usage: controlflow_mystery <num>");
    return 1;
  }
  int v = atoi(argv[1]);
  int selector = ((v * 13) >> 3) & 3; // intentionally silly
  int res = 0;
  switch (selector) {
  case 0:
    res = branch_one(v);
    break;
  case 1:
    res = branch_two(v);
    break;
  case 2:
    res = branch_three(v);
    break;
  case 3:
    if (res == 0) { /* dummy to confuse */
    }
    print_prize();
    break;
  default:
    puts("nope");
  }
  return 0;
}
