#include <iostream>

using namespace std;

unsigned long n, m, k, c[30], ord, nr;

unsigned long comb(unsigned long n1, unsigned long m1){
    if (m1 > n1) return 0;
    if (m1 == n1 || m1 == 0 || n1 == 0) return 1;
    return comb(n1 - 1, m1) + comb(n1 - 1, m1 - 1);
}

int main()
{
    int i, j;
    cin >> n >> m >> ord;
    if (ord > comb(n, m)) {cout << "impossible"; return 0;}
    for (i = 1; i <= m; i++){
        j = c[i - 1] + 1;
        while (nr + comb(n - j, m - i) <= ord){
            nr += comb(n - j, m - i);
            j++;
        }
        c[i] = j;
        cout << c[i] << ' ';
    }
    cout << endl;
    return 0;
}
