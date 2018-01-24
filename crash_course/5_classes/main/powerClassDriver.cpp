#include <iostream>
#include "../headers/powerClass.h"

using namespace std;

int main () {
  int k ;
  double x;
  cout <<" Enter an integer power " << endl;
  cin >> k ;
  Power powObj(k);
  cout <<" Enter the number to raise to "<< k << endl;
  cin >> x;
  cout << powObj.xToTheK(x) << endl;

  return 0 ;
}
