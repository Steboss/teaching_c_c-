#include <iostream>
#include "simpleMatrix.h"
using std::cout;using std::endl;


int main(){
  Matrix m1(2,2,1);
  cout <<"Here is an identity matrix "<< endl;
  m1.printMatrix();
  double ** p = new double*[3];
  for(int i=0; i<3; i++){
    p[i] = new double[2];
    for(int j = 0 ; j<2 ; j++){
      p[i][j]=(double)(i+1)*(j+1);
    }
  }

  Matrix *m2 = new Matrix(3,2,p);
  cout <<"Here is a matrix initialized by a pointer to pointer"<< endl;
  m2->printMatrix();
  return 0 ; 
}
