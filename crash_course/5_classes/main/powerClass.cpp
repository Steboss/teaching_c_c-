#include <iostream>
#include "../headers/powerClass.h"

using namespace std;

Power::Power(int k){
  if (k>=1){
    K =k;
  }
  else{
    cout<<"The power must be an integer >=1!"<< endl;
  }
}

double Power::xToTheK(double x){
  double y = 1.;
  for(int i=1; i<=K; i++)
  {
    y= x*y;
  }
  return y;
}
