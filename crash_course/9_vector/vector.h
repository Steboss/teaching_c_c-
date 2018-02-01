//define a vector
#ifndef VECTOR_H
#define VECTOR_H

class Vector{
  double *pA;
  int length;
  void pointerCheck() const;

public:
  Vector(int len = 0, double b=0.);
  Vector(int len, const double* pa);
  Vector(const Vector& v);
  ~Vector();

  Vector& operator=(const Vector& v);
  double operator[](int i) const{return pA[i];}
  void printVect() const;
  int getLength() const {return length;}

};

#endif
