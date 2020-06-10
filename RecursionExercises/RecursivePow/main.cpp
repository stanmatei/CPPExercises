#include <iostream>

using namespace std;

int pow(int x, int n){
    if(!n) return 1;
    return x * pow(x, n - 1);
}

//This one is more efficient

int altPow(int x, int n){
    int p;
    if(!n) return 1;
    if(n % 2){
        p = altPow(x, (n - 1) / 2);
        return x * p * p;
    }
    p = altPow(x, n / 2);
    return p * p;
}

int main()
{
    cout << altPow(2, 4);
    return 0;
}
