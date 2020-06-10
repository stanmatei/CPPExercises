#include <iostream>
#include <math.h>
using namespace std;

float a(int);
float b(int);
int n, a0, b0;

int main()
{
    cin >> n >> a0 >> b0;
    cout << b(n) << " " << a(n);
    return 0;
}


float a(int n){
    if(!n) return a0;
    else return (a(n - 1) + b(n - 1)) / 2;
}

float b(int n){
    if(!n) return b0;
    else return sqrt(a(n - 1) * b(n - 1));
}
