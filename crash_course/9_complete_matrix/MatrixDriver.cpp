#include "Matrix.h"
#include <iostream>


using std::cout; using std::endl;

void g(const Matrix& A){
  cout << "The function g was called"<< endl;
};


int main(){
  double **pMat = new double*[2];
  for (int i =0; i<2; i++){
    pMat[i] = new double[2];

    for (int j =0; j<2; j++){
      pMat[i][j] = (double) ((i+1)*(j+1)+j);
    }
  }


  Matrix m1(2,2,pMat);
  cout <<"Initialized a Matrix"<<endl;

  m1.printMatrix();

  for (int i=0; i<2 ;i++){
    delete [] pMat[i];
  }

  delete[] pMat;


  g(m1);
  Matrix m2;
  m2 = m1;
  cout <<" Copied matrix 1"<<endl;
  m2.printMatrix();
  return 0 ;
}
