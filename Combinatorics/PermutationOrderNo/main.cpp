#include <iostream>
#define MAXS 40
using namespace std;

int n, p[MAXS];
long int fact[MAXS], ord;

int main()
{
    cin >> n;
    int i, j;
    for (i = 1; i <= n; i++) cin >> p[i];
    fact[0] = 1;
    fact[1] = 1;
    for (i = 2; i <= n; i++) fact[i] = fact[i - 1] * i;
    for (i = 1; i <= n; i++){
        ord += fact[n - i] * (p[i] - 1);
        for (j = i + 1; j <= n; j++)
            if (p[j] > p[i]) p[j]--;
    }
    cout << ord;
    return 0;
}
