#include <iostream>

using namespace std;

int n, k;
long int p1[40], p2[40];

int main()
{
    int i, j;
    cin >> n;
    cin >> k;

    p1[0] = p2[0] = 1;
    for (i = 2; i <= n; i++){
        for (j = 1; j <= i * (i - 1) / 2; j++){
            p2[j] = p2[j - 1] - (j > n ? p1[j - n] : 0) + p1[j];
        }
        for (j = 1; j <= i * (i - 1) / 2; j++) p1[j] = p2[j];
    }

    return 0;
}
