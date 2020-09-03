#include <iostream>
#define MAXS 15
using namespace std;

int n, f[MAXS];

void gen(int k)
{
    if(k == n){
        for (int i = 0; i < n; i++) cout << f[i];
        cout << "   ";
    }
    else
    {
        for (int i = 1; i <= 4; i++){
            if(i % 2 == f[k - 1] % 2){
                f[k] = i;
                gen(k + 1);
            }
        }
    }
}


int main()
{
    cin >> n;
    for (int i = 1; i < 5; i++){
        f[0] = i;
        gen(1);
    }
    return 0;
}
