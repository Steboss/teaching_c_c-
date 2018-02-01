#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 5000 //max 5000 numbers


//void fill_array(double *a, double number,int position){

//  a[position] = number;

//}

double average(double *a, int length, double *results){

  double ave = 0.0, var = 0.0;
  double stddev ;
  double tmp;
  int counter =0  ;
  int j ;
  for (j=0; j<length;j++){
    if(counter==0){
      ave = a[j];
      var = 0.0;
      counter+=1;
    }
    else{
      tmp = ave;
      ave = ave + (a[j] - ave)/counter;
      var = (var + (a[j]- tmp)*(a[j] - ave))/counter;
      counter+=1;
    }

  }
  stddev = sqrt(var);
  results[0] = ave;
  results[1] = stddev;

}

int main () {
  //read the numbers.dat file
  FILE *ifile ;
  ifile = fopen("numbers.dat","r");
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
