#include "stdlib.h"
#include "stdio.h"
#include "sys/random.h"

void try_random_library() {
  unsigned char buf[16];
  int rc = getrandom(buf, sizeof(buf), 0);
  if (rc < 0) {
    perror("getrandom");
    exit(1);
  }
  for (int i = 0; i < sizeof(buf); i++) {
    printf("%02x ", buf[i]);
  }
  printf("\n");
}

int main() {
  try_random_library();
  return 0;

//  for (int i = 0; i < 10; i++) {
//    printf("Random number: %ld\n", random());
//  }
//
//  printf("----------------------------\n");
//  srandom(2);
//  for (int i = 0; i < 10; i++) {
//    printf("Random number: %ld\n", random());
//  }
//
//  printf("----------------------------\n");
//  srandomdev(); // alwasys use this before using random()
//  for (int i = 0; i < 10; i++) {
//    printf("Random number: %ld\n", random());
//  }
//
//  printf("----------------------------\n");
//  // use initstate
//  char state[256];
//  initstate(1, state, 256);
//  // print contents of state as integers  
//  for (int i = 0; i < 256; i++) {
//    printf("%d ", state[i]);
//  }
}
