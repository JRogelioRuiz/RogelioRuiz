#include <iostream>
using namespace std;

int main() {
    
    int a = 5;
    int* p;
    int* j;

    j = &a;

    p = new int;
    *p = a +2;
    a = *p +2;

    cout << "a: " << a << endl;
    cout << "&a: " << &a << endl;
    cout << "&p: " << &p << endl;
    cout << "p: " << p << endl;
    cout << "*p: " << *p << endl;
    cout<<j;


    return 0;
}