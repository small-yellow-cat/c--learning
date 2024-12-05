# include <iostream>
# include <vector>
# include "numerical_sequence.h"

using namespace std;

int main(){
    Fibonacci<8> fib1; Fibonacci<8,8> fib2;  Fibonacci<12,8> fib3;
    cout<<"fib1: "<<fib1<<'\n'<<"fib2: "<<fib2<<'\n'<<"fib3: "<<fib3<<endl;
    

}