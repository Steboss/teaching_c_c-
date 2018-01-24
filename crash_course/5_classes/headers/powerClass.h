#ifndef POWER_H
#define POWER_H

class Power{
  int K; //integer
public:
  Power(){K=1 ; } //NB the default integrator
  Power(int k);
  double xToTheK(double x);
};

#endif
