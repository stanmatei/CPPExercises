#include <iostream>
#define MAXS 30
using namespace std;

int f[MAXS];
int n, m;

void gen(int k) {
    if (k - 1 == m){
        for (int i = 1; i <= m; i++) cout << f[i] << " ";
        cout << endl;
    }
    else{
        for(int i = f[k - 1] + 1; i <= n - m + k; i++) {
            f[k] = i;
            gen(k + 1);
        }
    }
}

int main()
{
    cin >> n >> m;
    gen(1);
    return 0;
}
