// in this case we are going to pass a pointer to the function
#include<iostream>

using namespace std;

//recover the address here
void f(int * pi){
  pi[0] +=1;
}

int main(){

  int i = 0;
  int*pi = &i; //concatante pw ith i
  //the value of p is the address
  //so using *pi in teh funtion will give the address of p
  //which is the memory location of i
  //which can be modified accessing with pi[0]
  f(pi); //pass the address
  cout << "The value of i is "<< i << endl;
  return 0 ; 
}
