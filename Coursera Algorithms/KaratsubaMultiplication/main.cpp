#include <iostream>

using namespace std;

int Karatsuba(int x, int y){
    int pow = 0;
    if(x / 10 == 0){
        return x * y;
    }
    int p = x;
    while(p > 0){
        p /= 10;
        pow++;
    }
    int a, b, c, d, n, ac, bd, xy, abcd;
    n = 1;
    for(int i = 0; i < pow / 2; i++){
        n *= 10;
    }
    a = x / n;
    b = x % n;
    c = y / n;
    d = y % n;
    ac = Karatsuba(a, c);
    bd = Karatsuba(b, d);
    abcd = Karatsuba((a + b), (c + d)) - ac - bd;

    xy = n * n * ac + n * abcd + bd;


    return xy;

}


int main()
{
    cout << Karatsuba(5678, 1234) << endl;
    return 0;
}
