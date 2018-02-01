#include <iostream>


int powerTo(number, power){

  if (power==0){
    return 1;
  }
  if (power%2==0){
    number = powerTo(number, power/2);
    return number*number;
  }
  else{
    return number*powerTo(number, power-1);
  }
}


int main () {

  int numb, power, result;
  
  printf("Hello, give me a number\n");
  scanf("%d", &numb);
  printf("Now give me the power\n");
  scanf("%d", &power);
  printf("Computing the power...\n");
  result=powerTo(numb, power);
  printf("%d\n", result);
}
