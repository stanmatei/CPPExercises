#include <iostream>
#include <stdlib.h>
#include <algorithm>
#define MAXSIZE 10000

using namespace std;

struct genRand{
    int operator ()(){
        return rand()%10000;
    }
};
template <class T>
struct display{
    void operator ()(const T& x){
        cout << x << " ";
    }
};
int f[MAXSIZE];
int main()
{
    int n;
    cin >> n;
    genRand g;
    display<int> d;
    generate(f, f + n, g);
    //for(int i = 0; i < n; i++) cout << f[i] << " ";
    for_each(f, f + n, d);
    return 0;
}
