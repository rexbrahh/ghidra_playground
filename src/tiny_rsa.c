// tiny_rsa.c (small, insecure toy RSA)
#include <stdint.h>
#include <stdio.h>

// small toy modulus and exponent; not secure - for reversing only
static const uint64_t N = 0xC13F; // composite small
static const uint64_t E = 0x10001;
static const uint64_t SIG = 0x6A21; // pretend signature

uint64_t modexp(uint64_t a, uint64_t e, uint64_t m) {
  uint64_t res = 1;
  while (e) {
    if (e & 1)
      res = (res * a) % m;
    a = (a * a) % m;
    e >>= 1;
  }
  return res;
}

int main(void) {
  uint64_t v = modexp(SIG, E, N);
  if (v == 0x1234)
    puts("Signature valid - secret is RSA-OK");
  else
    puts("Signature invalid");
  return 0;
}
