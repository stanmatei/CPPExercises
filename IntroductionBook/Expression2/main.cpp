#include <iostream>

using namespace std;
float abs1(float);
float maxi(float, float);
float mini(float, float);

int main()
{
    float a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (a+b > c- d) ? maxi(mini(abs1(a) - 3 * b, c - 2 * abs1(d)), mini(abs1(a) + 3 * b, c + 2 * abs1(d))): mini(maxi(abs1(a) - 3 * b, c - 2 * abs1(d)), maxi(abs1(a) + 3 * b, c + 2 * abs1(d)));
    return 0;
}
float abs1(float x){
    if(x >= 0) return x;
    return -x;
}
float maxi(float a, float b){
    if(a >= b) return a;
    return b;
}
float mini(float a, float b){
    if(a <= b) return a;
    return b;
}
