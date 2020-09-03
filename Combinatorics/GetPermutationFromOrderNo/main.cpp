#include <iostream>
#define MAXS 100
using namespace std;

int n, p[MAXS];
long long k, fact[MAXS];
int main()
{
    int i, j;
    cin >> n >> k;
    fact[0] = 1;
    for (i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
    for (i = 1; i <= n; i++){
        p[i] = k / fact[n - i] + 1;
        k -= fact[n - i] * (p[i] - 1);
        cout << p[i] << " ";
    }
    cout << endl;
    for (i = n - 1; i >= 1; i--){
        for (j = i + 1; j <= n; j++)
            if (p[j] >= p[i]) p[j]++;
    }
    for (i = 1; i <= n; i++) cout << p[i] << " ";
    return 0;
}
