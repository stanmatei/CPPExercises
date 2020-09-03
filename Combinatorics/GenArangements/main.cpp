#include <iostream>
#define MAXS 30
using namespace std;
int m, n;
int f[MAXS], used[MAXS]
void gen(int k){
    if (k == m) {
        for (int i = 0; i < m; i++) cout << f[i] << " ";
        cout << endl;
    }
    else {
        for (int i = 1; i <= n; i++){
            if (!used[i]){
                f[k] = i;
                used[i] = 1;
                gen(k + 1);
                used[i] = 0;
            }
        }
    }
}


int main()
{
    cin >> n >> m;
    gen(0);
    return 0;
}
