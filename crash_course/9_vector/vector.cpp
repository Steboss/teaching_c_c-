#include "vector.h"
#include <iostream>
#include <cstdlib>

using std::cout; using std::endl;

Vector::Vector(int len, double b){

  length = len;

  if (length==0){
    pA=0;
    return ;
  }

  pA = new(std::nothrow)double[length]; //allocate the vector
  pointerCheck(); //check the poitner validy
  for (int i =0; i< length; i++){
    pA[i] = b;
  }

}

Vector::Vector(int len, const double*pa){
  length = len;
  pA = new(std::nothrow) double [length];
  pointerCheck();
  for(int i =0; i<len; i++){
    pA[i] = pa[i];
  }
}

Vector::Vector(const Vector& v){
  length = v.length;
  pA = new(std::nothrow) double[length];
  pointerCheck();
  for(int i =0; i<length; i++){
    pA[i] = v.pA[i];
  }
}

//destructor
Vector::~Vector(){
  if (pA!=0){
    delete [] pA;
  }

}

//operators
Vector& Vector::operator=(const Vector& v){
  //copy two vectors
  if(this == &v){
    return *this;
  }
  if( length !=v.length){
    if(pA!=0){
      delete[] pA;
    }
    length = v.length;
    pA  = new(std::nothrow) double[length];
    pointerCheck();
  }


  for (int i =0; i<length; i++){
    pA[i] = v.pA[i];
  }

  return *this;
}

void Vector::pointerCheck() const{
  if(pA==0){
    cout <<" Memory allocation for pA failed"<<endl;
    exit(1);
  }
}


void Vector::printVect() const{
  for(int i =0 ; i< length; i++){
    cout << "  " << pA[i] << "  " << endl;
  }
}
