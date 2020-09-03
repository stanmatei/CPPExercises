#include <iostream>
#define DMAX 30

using namespace std;

int n, m, f[DMAX], im[DMAX];

void genSurj(int k){
    if (k == n){
        int ok = 1;
        for (int i = 1; i <= m; i++){
            if (!im[i]) ok = 0;
        }
        if (ok)
        for (int i = 0; i < n; i++) cout << f[i] << ' ';
        cout << endl;
    }
    else {
        for (int j = 1; j <= m; j++){
            f[k] = j;
            im[j]++;
            gen(k + 1);
            im[j]--;
        }
    }
}

int main()
{

    return 0;
}
