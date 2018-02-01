//here we want to show the copy constrauct
#include "simpleMatrix.h"
#include <iostream>


using std::cout; using std::endl;

void g(Matrix A ){}; //here the copy constructor

int main() {
  Matrix m(2,2,1);
  g(m);
  //alternatively  Matrix m2;  m2 = m1; , without defining g
  return 0 ;
  //at the end we will have a malloc error
  //this is due to processes out of the scope
  //when we call g(m) we get into g scope and, there, a matrix is created
  //when we come back to the main, the code finishes, so the destructor is called
  //the destructr destroy m and m will point to NULL after that
  //this will raise an error since we are trying to delete g(m) but m -> NULL
  //to prevent this behaviour we need a real copy constructor
}
//for the copy constructro go into simpleMatrix.cpp and define:

Matrix:: Matrix(const Matrix& A){
  nRows= A.nRows;
  nCols = A.nCols;
  pA = new(std::nothrow) double*[nRows];
  pointerCheck();
  for(int i =0; i< nRows; i++){
    pA[i] = new(std::nothrow) double[nCols];
    pointerCheck(i);
  }
  for(int i= 0;i<nRows;i++){
    for(int j = 0;j<nCols; j++){
      pA[i][j] = A.pA[i][j];
    }
  }
}

//and inster in the haeader
Matrix(const Matrix& A);
