#include <iostream>
#define MAXS 30
using namespace std;

int n, f, p, m, sol[MAXS];

void gen(int k){
    if (k == p){
        for (int i = 0; i < p; i++) cout << sol[i] << ' ';
        cout << endl;
    }
    else{
        int i;
        if (k < m){
            for (i = sol[k - 1] + 1; i <= f; i++){
                sol[k] = i;
                gen(k + 1);
            }
        }
        else if (k == m){
            for (i = f + 1; i <= n - (p - m) + 1; i++){
                sol[k] = i;
                gen(k + 1);
            }
        }
        else{
            for (i = sol[k - 1] + 1; i <= n; i++){
                sol[k] = i;
                gen(k + 1);
            }
        }
    }
}

int main()
{
    cin >> n >> f >> p >> m;
    for (int i = 1; i <= f - m + 1; i++){
        sol[0] = i;
        gen(1);
    }
    return 0;
}
