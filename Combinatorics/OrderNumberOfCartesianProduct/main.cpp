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
    for (i = 0; i < n; i++) cin >> sol[i];
    for (i = 0; i < n; i++){
        total /= l[i];
        k += (sol[i] - 1) * total;
    }
    cout << k;

    return 0;
}
