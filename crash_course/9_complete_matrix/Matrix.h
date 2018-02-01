#ifndef MATRIX_H
#define MATRIX_H


class Matrix{
  int nRows, nCols;
  double **pA;
  void pointerCheck() const;
  void pointerCheck(int i ) const;

public:

  //constructors and destructor
  Matrix(int nrows=0, int ncols=0, double a = 0.);
  Matrix(int nrows, int ncols, const double* const* pa);
  Matrix(const Matrix& A); // NB this is the very definition of the copy constructor
  // general definition for it is:
  //className(const classnName& objectName)
  ~Matrix();

  Matrix& operator=(const Matrix &B); //here we are overloading the operator =
  //to define an overalod operator youcan follow this nomenclature:
  //className operatorSYMBOL(const className& ObjectName)
  //specifically Matrix& herfe since we have to pass by reference to copy
  Matrix operator+(const Matrix& B) const;
  Matrix& operator+=(const Matrix& B);
  Matrix operator*(const Matrix& B) const;
  Matrix operator*(double b) const;
  const double* operator[](int i) const {return pA[i];}


  Matrix trans() const;
  void printMatrix() const;
  int getnRows() const {return nRows;}
  int getnCols() const {return nCols;}


};


Matrix operator*(double, const Matrix& A);
#endif
