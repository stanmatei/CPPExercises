#include <iostream>
#define MAXS 100
using namespace std;

int n, k, sol[MAXS];

void gen(int p)
{
    if(sol[p - 1] == n + k){
        for (int i = 0; i < p; i++){
            cout << sol[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = sol[p - 1] + 1; i <= n + k; i++){
            sol[p] = i;
            gen(p + 1);
        }
    }
}


int main()
{
    cin >> n >> k;
    sol[0] = n;
    gen(1);
    return 0;
}
