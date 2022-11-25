#include "stdlib.h"
#include "stdio.h"

int main() {
  for (int i = 0; i < 10; i++) {
    printf("Random number: %ld\n", random());
  }

  printf("----------------------------\n");
  srandom(2);
  for (int i = 0; i < 10; i++) {
    printf("Random number: %ld\n", random());
  }

  printf("----------------------------\n");
  srandomdev(); // alwasys use this before using random()
  for (int i = 0; i < 10; i++) {
    printf("Random number: %ld\n", random());
  }

  printf("----------------------------\n");
  // use initstate
  char state[256];
  initstate(1, state, 256);
  // print contents of state as integers  
  for (int i = 0; i < 256; i++) {
    printf("%d ", state[i]);
  }
}