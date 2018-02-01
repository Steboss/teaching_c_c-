#include <iostream>
#include <cstdlib>
#include <time.h>
#include "vector.h"


using std::cout; using std::endl;


int main(){

  double *pVec = new double[3];
  srand(time(NULL));
  for(int i=0; i<3; i++){
    pVec[i] = rand()%10 +1;
  }

  Vector v(3, pVec);
  v.printVect();

  return 0 ;
}
