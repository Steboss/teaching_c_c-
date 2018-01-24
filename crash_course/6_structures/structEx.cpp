#include <iostream>

using namespace std;

struct X{
  int K;
};

int main() {
  X x;
  x.K = 1;
  cout << x.K << endl;
  return 0 ;
}
