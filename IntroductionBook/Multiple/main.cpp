#include <iostream>
//Find a multiple of n that has only 1 or 0 as decimal digits
using namespace std;

int pow10[10], d[10];

int main()
{
    int n, p, i;
    cin >> n;
    p = 1;
    i = 0;
    pow10[0] = 1;
    for(i = 1; i < 10; i++) pow10[i] = pow10[i - 1] * 10;
    d[0] = 1;
    do{
        p = 0;
        for(i = 0; i < 10; i++){
            p += d[i] * pow10[i];
        }
        i = 0;
        while(d[i] && i < 10) d[i++] = 0;
        d[i] = 1;
    }while(p % n);

    cout << p;

    return 0;
}
