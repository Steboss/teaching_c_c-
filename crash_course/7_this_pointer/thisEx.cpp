//this is aware of its own object memory location

#include <iostream>

using namespace std;

class X{
public:
  int K;
  X(){};
  X(int k){K=k;}

  X* getThis(){return this;}
  X& getThisRef(){return *this;}
};

int main(){
    X w(1);
    cout <<" w address = " << &w << endl;
    cout << "w value = "<< w.K << endl;

    X* x= w.getThis() ;
    cout <<"x value = "<< x << endl;
    x->K +=1 ;
    cout << "w.K = " << w.K << endl;

    X& y = w.getThisRef();
    cout << "y address = "<< &y << endl;
    y.K+=1;
    cout << "w.K = " << w.K << endl;
}
