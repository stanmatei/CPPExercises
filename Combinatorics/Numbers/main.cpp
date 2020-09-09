#include <iostream>
#define MAXS 40

//Calculate the number of numbers of exactly n digits that do not have three consecutive identical digits
using namespace std;

int d[MAXS], id[MAXS];

int main()
{
    int i, j, n, sol = 0;
    cin >> n;
    d[1] =  9;
    id[1] = 0;
    for (i = 2; i <= n; i++){
        id[i] = d[i - 1];
        d[i] = 9 * id[i - 1] + 9 * d[i - 1];
    }
    sol =  id[n] + d[n];
    cout << sol;
    return 0;
}
