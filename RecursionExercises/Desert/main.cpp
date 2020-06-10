#include <iostream>

using namespace std;

int n, k;
long double p;

long double dist(int n){
    if(n <= 2) return n * k / p;
    else return k / ((2 * n - 3) * p) + dist(n - 1);
}

int main()
{
    long double d;
    cin >> n >> k >> p;
    p = p /100;
    d = dist(n);
    cout << d;
    return 0;
}
