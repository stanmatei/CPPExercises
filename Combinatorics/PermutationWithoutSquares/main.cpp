#include <iostream>
#define MAXS 20
using namespace std;

int n, f[MAXS], used[MAXS];

int abs_val(int x){
    if(x < 0) return -x;
    return x;
}
void gen(int k)
{
     if (k == n + 1){
        for (int i = 1; i <= n; i++) cout << f[i] << " ";
        cout << endl;
     }
     else{
        int i, j, ok;
        for (i = 1; i <= n; i++){
            if (!used[i]){
                for (ok = 1, j = 1; j < k && ok; j++)
                    if(abs_val(k - j) == abs_val(i - f[j])) ok = 0;
                if (ok){
                    used[i] = 1;
                    f[k] = i;
                    gen(k + 1);
                    used[i] = 0;
                }
            }
        }
     }
}


int main()
{
    cin >> n;
    gen(1);
    return 0;
}
