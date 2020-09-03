#include <iostream>
#define MAXS 100
using namespace std;

int a, b, f[MAXS], s, len = 0, sol[MAXS];

void gen(int k)
{
    if(s >= b){
        if(s == b){
            if(k > len){
                len = k;
                for (int i = 0; i < k; i++) sol[i] = f[i];
            }
        }
    }
    else{
        int i;
        for (i = f[k - 1] * 2; i <= b - s; i++){
            f[k] = i;
            s += i;
            gen(k + 1);
            s -= i;
        }
    }
}

int main()
{
    cin >> a >> b;
    f[0] = a;
    s += a;
    gen(1);
    for (int i = 0; i < len; i++) cout << sol[i] << " ";
    return 0;
}
