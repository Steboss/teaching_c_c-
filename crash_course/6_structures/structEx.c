#include <stdio.h>


typedef struct {
    int K;

} X;

int main() {
  X x;
  x.K = 1;
  printf("%d\n", x.K );
  return 0 ;
}
