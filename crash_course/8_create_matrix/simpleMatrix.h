#ifndef SIMPLEMATRIX_H
#define SIMPLEMATRIX_H


class Matrix{
  int nRows  , nCols;
  double **pA;

  void pointerCheck() const;
  void pointerCheck(int i) const;

public:

  Matrix(int nrows=0, int ncols=0, double a = 0 );
  Matrix(int nrows, int ncols, const double* const* pa);
  ~Matrix();


  void printMatrix() const;
  int getnRows() const {return nRows;}
  int getnCols() const {return nCols;}
};

#endif
