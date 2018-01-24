///here we show how to use the reference to change value
#include<iostream>

using namespace std;

//recover the address here
void f(int &pi){
  pi+=1;
}

int main(){

  int i = 0;
  int &pi = i;
  f(pi);
  cout << "The value of i is "<< i << endl;
  return 0 ;
}
