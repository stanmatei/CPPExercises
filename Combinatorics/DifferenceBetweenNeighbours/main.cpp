#include <iostream>
#define MAXS 20
using namespace std;

int sol[MAXS], n, ok, v, used[MAXS];

int abs_val(int x){
    if (x < 0) return -x;
    return x;
}

void gen(int k){

    if (k == n){
        for (int i = 0; i < n; i++) cout << sol[i] << "  ";
        cout << endl;
        ok = 1;
    }
    else{
        int a;
        for (int i = 1; i <= n; i++){
            a = abs_val(sol[k - 1] - i);
            if (!used[i] && a > v){
                used[i] = 1;
                sol[k] = i;
                gen(k + 1);
                used[i] = 0;
            }
        }
    }
}

int main()
{
    cin >> n >> v;
    for (int i = 1; i <= n; i++){
        sol[0] = i;
        used[i] = 1;
        gen(1);
        used[i] = 0;
    }
    if (!ok) cout << "impossible";
    return 0;
}
