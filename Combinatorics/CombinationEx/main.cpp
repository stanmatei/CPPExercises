#include <iostream>

using namespace std;

int f[128], n, m, s, r;
void gen(int k){
    if (k < 128){
        if (s >= m){
            if (s == m) r++;
        }
        else{
            int i, j;
            for (i = 0; i <= f[k] && i <= m - s; i++){
                s += i;
                gen(k + 1);
                s -= i;
            }
        }
    }
}

int main()
{
    int i, j;
    cin >> n >> m;
    for (i = 0; i < n; i++){
        cin >> j;
        f[j]++;
    }
    gen(0);
    cout << r;
    return 0;
}
