//if a pointer is passed by value to a function, the vlaue of the pointer
//iself cannot be changed
//namely the function cannot change the address the pointer points to in memory

//However, the function does have access to the memory location pointed to
//by the pointers
//it can thus change the values stored in the memory locations associated with a pointer
//So passing a memory address is the key
#include <stdio.h>
#include <stdlib.h>

void f(int i ){
  i+=1;
}


int main () {
  int i = 0 ;
  f(i);
  printf("The value of i is %d\n", i);
  return 0 ;
}
// this is an important reslt
//the value of the variable IS NOT CHANGED by the function
