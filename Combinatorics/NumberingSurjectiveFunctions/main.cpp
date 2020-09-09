#include <iostream>
#define MAXS 30
using namespace std;

long long c1[30], c2[30];
int n, s;
int main()
{
    cin >> n >> s;
    int i, j;
    c1[0] = c1[1] = c2[0] = 1;
    for (i = 2; i <= n; i++){
        for (j = 1; j < i; j++){
            c2[j] = c1[j - 1] + c1[j];
        }
        c2[i] = 1;
        for (j = 1; j <= i; j++) c1[j] = c2[j];
    }
    cout << ((1 << s) - 2) * c2[s];
    return 0;
}
