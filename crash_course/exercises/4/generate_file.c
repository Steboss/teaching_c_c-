#include <stdio.h>
#include <stdlib.h>

#define LIMIT 5000
//generate random number in a file

int main () {

  FILE *ifile ;
  ifile = fopen("numbers.dat","w");
  int rand_len,i ;
  double rand_float ;
  //fix the seed
  srand(time(NULL));
  //now generate a random number which is
  //how many number we want
  rand_len = rand()%100 +1; //generate a random number between 1 and 100
  for (i=0; i<rand_len;i++){
    rand_float= (float)rand()/(float)(RAND_MAX/LIMIT);
    fprintf(ifile,"%f\n",rand_float);
  }

  fclose(ifile);

}
