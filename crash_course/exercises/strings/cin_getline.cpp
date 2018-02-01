#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {

    char buffer[100];
    cout<< "What's your name?"<<endl;
    cin.getline(buffer,100);
    cout<<"Hello "<< buffer << endl;
    return 0 ;
}
