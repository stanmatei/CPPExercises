#include <iostream>
#define MAXS 20
using namespace std;

int n, x, y, f[MAXS], used[MAXS];

void gen(int k) {
    if (k == n) {
        for (int i = 0; i < n; i++) cout << f[i];
        cout << endl;
    }
    else{
        int i;
        for (i = 1; i < x; i++){
            if (!used[i]){
                f[k] = i;
                used[i] = 1;
                gen(k + 1);
                used[i] = 0;
            }
        }
        for (i = y + 1; i <= n; i++){
            if (!used[i]){
                f[k] = i;
                used[i] = 1;
                gen(k + 1);
                used[i] = 0;
            }
        }
        if (!used[x]){
            for (i = x; i <= y; i++) f[k++] = i;
            used[x] = 1;
            gen(k);
            k -= (y - x + 1);
            used[x] = 0;
        }
    }
}

int main()
{
    cin >> n >> x >> y;
    gen(0);
    return 0;
}
