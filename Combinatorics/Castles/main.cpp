#include <iostream>

using namespace std;

int n, m, k;

unsigned long newL[50], oldL[50];


int main()
{
    int i, j, aux;
    cin >> n >> m >> k;

    unsigned long f = 1, cmk;
    for(i = 1; i <= k; i++) f *= i;
    newL[0] = oldL[0] = 1;
    if (n < m) {
        aux = n;
        n = m;
        m = aux;
    }
    for (i = 1; i <= n; i++){
        for (j = 1; j <= i; j++)
            newL[j] = oldL[j - 1] + oldL[j];
        for (j = 1; j <= i; j++) oldL[j] = newL[j];
        if (i == m) cmk = newL[k];
    }
    cout << cmk * f * newL[k];
    return 0;
}
