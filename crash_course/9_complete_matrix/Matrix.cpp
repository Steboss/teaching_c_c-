#include <iostream>
#include <cstdlib>
#include "Matrix.h"


using std::cout; using std::endl;


Matrix::Matrix(int nrows, int ncols, double a){
  nRows = nrows;
  nCols = ncols;
  if (nRows== 0 || nCols == 0) {
    pA = 0 ;
    return ;
  }

  pA = new(std::nothrow) double*[nRows];
  pointerCheck();

  for(int i =0 ; i<nRows; i++){
    pA[i] =new(std::nothrow) double[nCols];
    pointerCheck(i);
    for(int j=0; j<nCols; j++){
      if(i==j){
        pA[i][j] = a;
      }
      else{
        pA[i][j] = 0. ;
      }
    }
  }
}


Matrix::Matrix(int nrows, int ncols, const double* const* pa){

    nRows = nrows;
    nCols = ncols;
    pA = new(std::nothrow) double *[nRows];
    pointerCheck();

    for(int i =0; i<nRows; i++){
      pA[i] = new(std::nothrow) double[nCols];
      pointerCheck(i);
    }

    for (int i =0; i<nRows;i++){
      for(int j =0 ; j<nCols; j++){
        pA[i][j] = pa[i][j];
      }
    }
}

Matrix::~Matrix(){
  if(pA!=0){
    for(int i =0; i<nRows;i++){
      delete [] pA[i];

    }
    delete [] pA;
  }
}



void Matrix::printMatrix() const {
for(int i =0;i<nRows;i++){
  for(int j =0;j<nCols;j++){
    cout <<" "<< pA[i][j]<< " ";

  }
  cout << endl;
}}


void Matrix::pointerCheck() const{
  if(pA==0){
    cout<<"Memory allocation for pA failed"<< endl;
    exit(1);
  }
}


void Matrix::pointerCheck(int i) const{
  if(pA[i]==0){
    cout<<"Memory allocation fo pA["<<i<<"] failed"<<endl;
    exit(1);
  }
}


//define the new operator
Matrix& Matrix::operator=(const Matrix& A){

  if(this==&A)// so A=A
    return *this;

  //check the dimensions
  if (nRows!= A.nRows || nCols != A.nCols){
    if(pA!=0){
      this->~Matrix();
    }

    nRows = A.nRows;
    nCols = A.nCols;
    pA = new(std::nothrow) double*[nRows];
    pointerCheck();

    for(int i =0; i< nRows; i++){
      pA[i] = new(std::nothrow) double[nCols];
      pointerCheck(i);
    }

    for(int i =0; i<nRows; i++){
      for (int j =0;j<nRows; j++){
        pA[i][j] = A.pA[i][j];
      }
    }

    return *this;
  }

}

Matrix Matrix::operator+(const Matrix& B) const{
  if(nRows!=B.nRows || nCols !=B.nCols){
    cout<<"Bad row and/or column dimensions in + !"<< endl;
    exit(1);
  }

  Matrix temp(nRows, nCols);
  for ( int i =0; i<nRows; i++){
    for(int j=0; j< nCols; j++){
      temp.pA[i][j] = this->pA[i][j] + B.pA[i][j]; //or pA[i][j] + B.pA[i][j]

    }

  }

  return temp;
}


Matrix& Matrix::operator+=(const Matrix&B){
  if(nRows!=B.nRows || nCols !=B.nCols){
    cout<<"Bad row and/or column dimensions in + !"<< endl;
    exit(1);
  }

  for ( int i =0; i<nRows; i++){
    for(int j=0; j< nCols; j++){
      pA[i][j] += B.pA[i][j];

    }

  }
  return *this;

}



Matrix Matrix::operator*(const Matrix& B) const{
  if(nRows!=B.nRows || nCols !=B.nCols){
    cout<<"Bad row and/or column dimensions in + !"<< endl;
    exit(1);
  }

  Matrix C(nRows, B.nCols);
  for(int i =0; i< nRows; i++){
    for (int j=0; j<B.nCols;j++){
      for (int k=0; k<B.nRows; k++ ){
        C.pA[i][j] += pA[i][k]*B.pA[k][j];
      }
    }
  }

  return C;
}

Matrix Matrix::operator*(double b) const{
  Matrix C(nRows,  nCols);
  for(int i=0; i<nRows; i++){
    for(int j =0; j<nCols; j++){
      C.pA[i][j] = b*pA[i][j];
    }
  }

  return C;
}

Matrix operator*(double b, const Matrix&A){
  return A*b;
}

Matrix Matrix::trans() const{
  Matrix B(nCols, nRows,0.);
  for(int i=0; i<nRows; i++){
    for(int j =0; j<nCols; j++){
      B.pA[i][j] = pA[j][i];
    }
  }

  return B;
}
