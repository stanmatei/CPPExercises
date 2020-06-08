#include <iostream>
#include <math.h>
using namespace std;

struct complex_no{
    double a, b;
}a, b, z, c, d;

double abs(complex_no x){
    return sqrt(x.a * x.a + x.b * x.b);
}
complex_no pow2(complex_no x){
    double c, d;
    c = x.a;
    d = x.b;
    x.a = x.a * x.a - x.b * x.b;
    x.b = 2 * c * d;
    return x;
}

complex_no mult(complex_no x, complex_no y){
    complex_no res;
    res.a = x.a * y.a - x.b * y.b;
    res.b = x.a * y.b + x.b * y.a;
    return res;
}

complex_no add(complex_no x, complex_no y){
    complex_no res;
    res.a = x.a + y.a;
    res.b = x.b + y.a;
    return res;
}



int main()
{
    cin >> a.a >> a.b;
    cin >> b.a >> b.b;
    cin >> z.a >> z.b;

    if(abs(z) < 1){
        c.a = 3;
        c.b = 0;
        c = mult(c, pow2(z));
        d.a = -6;
        d.b = 0;
        d = mult(d, mult(a, z));
        c = add(add(c, d), b);
        cout << c.a << " " << c.b;
    }
    if(abs(z) > 1){
        c.a = 6;
        c.b = 0;
        d.a = -1;
        d.b = 0;
        c = add(mult(mult(c, a), z), mult(d, b));
        cout << c.a << " " << c.b;
    }
    return 0;
}

