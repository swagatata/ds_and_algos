#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

/* single global variable */
/* shared, accessible, modifiable by all threads */
int accum = 0;

void *square(void *x)
{
  int xi = (int)x;
  accum += xi * xi;
  return NULL; /* nothing to return, prevent warning */
}

int main(int argc, char **argv)
{
  int i;
  pthread_t ths[20];
  for (i = 0; i < 20; i++)
  {
    pthread_create(&ths[i], NULL, square, (void *)(i + 1));
  }

  for (i = 0; i < 20; i++)
  {
    void *res;
    pthread_join(ths[i], &res);
  }

  printf("accum = %d\n", accum);
  return 0;
}