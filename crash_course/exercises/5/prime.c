#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream.h>
#include <math.h>

#define N 10 //max of prime numbers


int main () {
  //read the numbers.dat file
  FILE *ifile ;
  ifile = fopen("prime_numbers.dat","w");
  int len ; //limit of numbers

  for(int i = 1; i< N; i++){
    for (int j=i+1; j< N; j++){
      
    }
  }
  for (; ; ){
    if(len == N){
      break;
    }
    else{
      //compute the numbers

    }
  }

  double number, ave,stddev;
  double *ptr  = malloc(N*sizeof(double));
  double *results = malloc(2*sizeof(double));

  //read the file and print the lines
  int i, len;
  for(i=0; i< N; i++){
    if(feof(ifile)){
      break;
    }
    else{
      fscanf(ifile, "%lf", &ptr[i]);
      len+=1;
      //fscanf(ifile,"%lf", &number);
      //fill_array(ptr, number,i);
    }
  }

  //now compute the average //pass len-1
  /*for (i=0; i<len-1;i++){
    printf("%lf\n", ptr[i]);
  }*/
  ave,stddev = average(ptr, (len-1), results);
  printf("The average is %lf +/- %lf\n", results[0],results[1]);
  free(ptr);


}
