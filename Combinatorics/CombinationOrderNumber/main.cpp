#include <iostream>

using namespace std;
unsigned long n, m, c[20], ord;
long comb(unsigned long n1, unsigned long m1){
    if (m > n) return 0;
    if (m == n || m == 0 || n == 0) return 1;
    return comb(n1 - 1, m1) + comb(n1 - 1, m1 - 1);
}

int main()
{
    int i, j;
    cin >> n >> m;
    for (i = 1; i <= m; i++) cin >> c[i];
    for (i = 1; i <= m; i++){
        for (j = c[i - 1] + 1; j < c[i]; j++)
            ord += comb(n - j, m - i);
    }
    return 0;
}
