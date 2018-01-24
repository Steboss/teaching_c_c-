//example  as passing by reference

#include<iostream>

using namespace std;

//recover the address here
void f(int &j){
  j++;
  cout << &j << endl;
}

int main(){

  int i = 2;
  cout << &i << endl;
  f(i);
  cout << i << endl;

  int & j = i ;
  int k = j ;
  f(j);
  cout << i << " " << j << " " <<  k << endl;
  cout << &i<< " "<< &j << " " <<  &k << endl;

  k++;
  j=k;
  cout << i << " " << j << " " <<  k << endl;
  cout << &i<< " "<< &j << " " <<  &k << endl;
  return 0 ;
}
