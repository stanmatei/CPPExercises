#include <iostream>
#include <fstream>
#define MAX 100

// Calculate the gcd of a set of integers.

using namespace std;
ifstream in("input.txt");
int a[MAX], n;

int Euclid(int x, int y);
int gcd(int p ,int q);


int main()
{
    in >> n;
    for(int i = 0; i < n; i++) in >> a[i];
    cout << gcd(0, n- 1);
    return 0;
}

int Euclid(int x, int y){
    int p;
    while(y){
        p = x % y;
        x = y;
        y = p;
    }
    return x;
}

int gcd(int p, int q){
    if(p - q <= 1) Euclid(a[p], a[q]);
    else{
        int m = (p + q) / 2;
        return Euclid(gcd(p, m), gcd(m + 1, q));
    }
}
