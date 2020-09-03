#include <iostream>
#define MAXS 30
using namespace std;

int n, k;
long int m1[MAXS], m2[MAXS];

int main()
{
    cin >> n >> k;
    int i, j;
    m1[0] = m1[1] = m2[1] = 1;
    for (i = 2; i <= n; i++){
        for (j = 2; j <= k; j++){
            m2[j] = j * m1[j];
            if (i - j + 1 <= 0) continue;
            m2[j] += (i - j + 1) * m1[j - 1];
        }
        for (j = 2; j <= k; j++) m1[j] = m2[j];
    }
    cout << m1[k];
    return 0;
}
