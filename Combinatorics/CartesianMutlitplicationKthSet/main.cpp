#include <iostream>
#define MAXS 30
using namespace std;

int sol[MAXS], l[MAXS], n;

long int k, total = 1;


int main()
{
    int i, j;
    long int aux;
    cin >> n >> k;
    for (i = 0; i < n; i++){
        cin >> l[i];
        total *= l[i];
    }
    for (i = 0; i < n; i++){
        total /= l[i];
        sol[i] = k / total + 1;
        k -= (sol[i] - 1) * total;
    }
    for (i = 0; i < n; i++) cout << sol[i] << " ";


    return 0;
}
