// got_plt_demo.c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  puts("Calling puts via PLT");
  puts("Hello from PLT!");
  return 0;
}
