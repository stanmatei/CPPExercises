#include <iostream>
#define MOD 997
#define NMAX 1001

using namespace std;

long s[NMAX][NMAX];
long comb[NMAX], res;
int n, p, q;
void det_combinations();
void det_s();


int main()
{
    int k;
    cin >> n >> p >> q;
    det_combinations();
    det_s();
    if (p == 1) res = s[n - 1][q - 1];
    else {
        for (k = p; k <= n - q + 1; k++)
            res = (res + comb[k - 1] * s[k - 1][p - 1] * s[n - k][q - 1]) % MOD;
    }
    cout << res;
    return 0;
}

void det_combinations(){
    long c[NMAX];
    int i, j;
    c[0] = comb[0] = c[1] = 1;
    for (i = 2; i < n; i++){
        for (j = 1; j < i; j++) comb[j] = (c[j - 1] + c[j]) % MOD;
        comb[i] = 1;
        for (j = 1; j <= i; j++) c[j] = comb[j];
    }
}

void det_s(){
    int i, j;
    s[1][1] = 1;
    for (i = 2; i < n; i++)
        s[i][1] = (s[i - 1][1] * (i - 1)) % MOD;
    for (i = 2; i < n; i++){
        for (j = 2; j <= i; j++)
            s[i][j] = (s[i - 1][j - 1] + (i - 1) * s[i - 1][j]) % MOD;
    }

}
