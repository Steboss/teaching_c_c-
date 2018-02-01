#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

using std::cout; using std::endl;

#define N 5000 //max 5000 numbers

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

  FILE *ifile = fopen("numbers.dat","r");
  if (!ifile) {
    cout << "Unable to open file datafile.txt";
    exit(1);   // call system to stop
  }
  //create a pointer
  double *ptr = new(std::nothrow) double[N];
  double ave, stddev;
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
  double *results = new(std::nothrow) double[len];

  average(ptr, (len-1), results);
  printf("The average is %lf +/- %lf\n", results[0],results[1]);
  free(ptr);


}
