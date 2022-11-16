// Caution:
// Modify C file
// mpp copy C->CPP

#include <stdio.h>

struct Cont {
	int a;
	int b;
	int c;
};

void p(const struct Cont * cont_in) {
    printf("a == %d\n", cont_in->a);
    printf("b == %d\n", cont_in->b);
    printf("c == %d\n", cont_in->c);
}

int main() {
  #ifndef __cplusplus
  // C Style 1
  //  Good, no UB.
  if (1) {
    printf("Style 1: Good (no UB, all fields initialized)\n");
    printf("  Zero init\n");
    struct Cont cont_z = {0}; // Good
    p(&cont_z);
    printf("  Partial fields init\n");
    struct Cont cont = {.b = 1, .c = 10}; // Good
    p(&cont);
  }
  // C Style 2 - Do not use
  // Undefined Behaviour:
  // All fields not listed are unitialyzed.
  if (1) {
    printf("Style 2: UB (UB, potentially uninitialized fields)\n");
    struct Cont cont; // Do not use
    cont.b = 20;
    cont.c = 30;
    p(&cont);
  }
  #endif
  #ifdef __cplusplus
  // C++ Style
  if (1) {
    printf("C++ Style: Good (no UB, all fields initialized)\n");
    struct Cont cont {}; // Good style, Zero init
    cont.b = 20;         // We specify fields to init here
    cont.c = 30;         //
    p(&cont);
  }
  #endif
}
