#include <iostream>

using namespace std;

int maxi(int x, int y);
int mini(int x, int y);
int abs(int x);

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(c + d <= 3){
        cout << maxi(abs(a) - 3, abs(b) - 6);
    }
    else
        cout << (c + d < 7) ? mini(abs(a) - 3, abs(b) + 6) : mini(abs(a) + abs(b), 18);
    return 0;
}

int maxi(int x, int y){
    if(x > y) return x;
    return y;
}

int mini(int x, int y){
    if(x > y) return y;
    return x;
}
int abs(int x){
    if(x > 0){
        return x;
    }
    return -x;
}



