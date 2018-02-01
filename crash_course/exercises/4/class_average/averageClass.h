#ifndef AVERAGE_H
#define AVERAGE_H


class Average{
  //compute the average with a class
  //create an average object
  int N; //length
  double *pA; //vector with values

public:

  Average(const std::string& filename);//construct
  ~Average(); //destructor
  //double computeAverage();
  void printarray();
  double computeAverage();

};

#endif
