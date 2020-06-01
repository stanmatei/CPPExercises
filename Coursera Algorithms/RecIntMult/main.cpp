#include <iostream>

using namespace std;

int RecIntMult(int x, int y){
    int pow = 0;
    if(x / 10 == 0){
        return x * y;
    }
    int p = x;
    while(p > 0){
        p /= 10;
        pow++;
    }
    int a, b, c, d, n, ac, bd, xy, ad, bc;
    n = 1;
    for(int i = 0; i < pow / 2; i++){
        n *= 10;
    }
    a = x / n;
    b = x % n;
    c = y / n;
    d = y % n;
    ad = RecIntMult(a, d);
    ac = RecIntMult(a ,c);
    bc = RecIntMult(b, c);
    bd = RecIntMult(b, d);
    xy = n * n * ac + n * (ad + bc) + bd;


    return xy;

}


int main()
{
    cout << RecIntMult(5678, 1234) << endl;
    return 0;
}
