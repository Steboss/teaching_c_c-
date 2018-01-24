//example of aclass in C++

#include <iostream>

using namespace std;

class Power{
  int K;

public:
  Power(int k);
  double xToTheK(double x);
}; //NB we have a ; here

Power::Power(int k ){
  if (k>=1){
    K = k;
  }
  else {
    cout << "The power must be  an integer >=1!"<<endl;
  }
}

double Power::xToTheK(double x){
  double y = 1.;
  for (int i = 1; i<=K; i++) {
    y = x*y;
  }
  return y;
}

int main () {
  int k ;
  double x;
  cout <<"Enter an integer power\n";
  cin >> k;
  Power* pPow = new Power(k);

  cout << "Enter a number to raise to this power\n";
  cin >> x;
  cout << pPow->xToTheK(x)<<endl;
  delete pPow;
  return 0 ;
}
