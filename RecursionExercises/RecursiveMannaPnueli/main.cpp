#include <iostream>

using namespace std;
int f(int x){
    if(x >= 12) return x - 1;
    else return f(f(x + 2));
}
int main()
{
    cout << f(4);
    return 0;
}
