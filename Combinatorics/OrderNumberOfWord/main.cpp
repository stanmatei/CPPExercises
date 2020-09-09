#include <iostream>
#include <string.h>
#define MAXS 20
using namespace std;

char word[MAXS];

long int k, p[MAXS];

int main()
{
    int i;
    cin.getline(word, MAXS);
    k = 1;
    p[0] = 1;
    int n = strlen(word);
    for (i = 1; i < n; i++) p[i] = p[i - 1] * ('z' - 'a' + 1);
    for (i = 0; i < n; i++){
        k += (word[i] - 'a') * p[n - i - 1];
    }
    cout << k;
    return 0;
}
