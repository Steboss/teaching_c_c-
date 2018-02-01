#include <iostream>
#include <cstdlib>
#include "averageClass.h"

using std::cout;using std::endl;


int main() {
  //create a average object
  std::string filename="numbers.dat";

  double real_avg ;
  Average avg_obj(filename);
  //avg_obj.printarray();
  real_avg = avg_obj.computeAverage();//
  cout << "Hello from the main  "<< real_avg <<endl;

}
