///here we show how to use the reference to change value
#include<stdio.h>
#include<stdlib.h>


//recover the address here
void f(int &pi){
  pi+=1;
}

int main(){
  int i = 0;
  int *pi = i ;
  f(&pi)
  //f(pi);
  //printf("The value of i is %d\n" , i);
  //return 0 ;
}
