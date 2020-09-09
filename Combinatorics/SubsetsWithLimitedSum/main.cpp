#include <iostream>
#define MAXS 20
using namespace std;

int n, vmax, f[MAXS], s, m;

void gen(int k){
    if (k == m){
        if (s <= vmax){
            for (int i = 0; i < m; i++) cout << f[i] << ' ';
            cout << endl;
        }
    }
    else{
        int i;
        for (i = f[k - 1] + 1; i <= n; i++){
            if (s + i <= vmax){
                s += i;
                f[k] = i;
                gen(k + 1);
                s -= i;
            }
        }


    }
}

int main()
{
    cin >> n >> m >> vmax;
    gen(0);
    return 0;
}
