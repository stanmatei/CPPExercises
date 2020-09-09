#include <iostream>

using namespace std;


long int n1[40], n2[40];
int n, k;

int main()
{
    int j, i, sum;
    n1[1] = 1;
    cin >> n >> k;
    for (i = 4; i <= n; i++){
        for (j = 1; j <= k; j++)
            n2[j] = j * 2 * n1[j] + (i - 1 - 2 * (j - 1)) * n1[j - 1];
        for (j = 1; j <= k; j++) n1[j] = n2[j];
    }
    for (i = 1; i <= k; i++) sum += n1[i];
    cout << sum;
    return 0;
}
