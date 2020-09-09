#include <iostream>
#include <string.h>
#define MAXS 20
using namespace std;

char word[MAXS];

long int k, p[MAXS];

int main()
{
    int i, n;
    cin >> n >> k;
    k--;
    p[0] = 1;
    for (i = 1; i < n; i++) p[i] = p[i - 1] * ('z' - 'a' + 1);
    for (i = 0; i < n; i++){
        word[i] = k / p[n - i - 1] + 'a';
        k -= (word[i] - 'a') * p[n - i - 1];
    }
    cout << word;
    return 0;
}
