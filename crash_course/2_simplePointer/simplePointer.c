#include <stdio.h>
#include <stdlib.h>


int main () {

  int * p = 0;
  int i = 1 ;
  p = &i;
  printf("Address of i %x\n", &i);
  printf("Address of p %x\n", &p);
  printf("Value of p   %x\n", p); // value of memory
  printf("Value stored in p %d\n", *p); //real value
  printf("Value stored in p %d\n", p[0]);
  return 0 ;
}
