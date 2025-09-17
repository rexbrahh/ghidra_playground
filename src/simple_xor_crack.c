// simple_xor_crack.c
#include <stdint.h>
#include <stdio.h>
#include <string.h>

static uint8_t enc_secret[] = {
    0x2b, 0x0f, 0x1a, 0x10, 0x07, 0x5b, 0x00,
    0x0b, 0x1a, 0x10, 0x2f, 0x5d}; // encrypted "FLAG{ghidra_fun}\0" XORed with
                                   // 0x55

int check_password(const char *pw) {
  size_t n = strlen(pw);
  uint8_t sum = 0;
  for (size_t i = 0; i < n; ++i)
    sum += (uint8_t)pw[i];
  return (sum % 0x7f) == 0x1f; // weak check intentionally
}

void decrypt_and_print(void) {
  size_t n = sizeof(enc_secret);
  char buf[64] = {0};
  for (size_t i = 0; i < n; ++i)
    buf[i] = enc_secret[i] ^ 0x55;
  printf("Secret: %s\n", buf);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    puts("Usage: simple_xor_crack <password>");
    return 1;
  }
  if (check_password(argv[1])) {
    decrypt_and_print();
    return 0;
  } else {
    puts("Wrong password.");
    return 2;
  }
}
