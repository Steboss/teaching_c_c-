#include <iostream>
#include <cstdlib>
#include <fstream>
#include "averageClass.h"

using std::cout; using std::endl;


Average::Average(const std::string& filename){

  pA = new(std::nothrow) double [1000];
  //open the file
  int len=0;
  FILE *ifile = fopen("numbers.dat","r");

  for(int i =0; i< 1000; i++){
    if(feof(ifile)){
      break;
    }
    else{
      fscanf(ifile, "%lf", &pA[i]);
      len+=1;
      //fscanf(ifile,"%lf", &number);
      //fill_array(ptr, number,i);
    }
  }
  cout << "Total number of elements " << len << endl;
  N = len-1;
  cout << "N set to "<< N << endl;


}


Average::~Average(){
  if(pA!=0){
    delete [] pA;
  }
}

void Average::printarray(){

  for (int i = 0; i< this->N; i++){
    cout << " " << pA[i] << " " <<endl;
  }
}

double Average::computeAverage(){

  double avg = 0.0;
  int counter = 0;
  cout << "N is "<< this -> N << endl;
  for (int i=0; i<this->N;i++){
    if (counter==0){
      avg = pA[i];
      counter+=1;
    }
    else{
      avg = avg + (pA[i] - avg)/counter;
      counter+=1;
    }
  }
  cout<<"Average "<< avg << endl;
  return avg;

}
