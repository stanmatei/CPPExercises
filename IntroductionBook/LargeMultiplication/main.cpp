#include <iostream>
#include <string.h>
#define MS 1000
using namespace std;
typedef int big[MS];

void multiplication(big a, int la, big b, int lb, big r, int &lr)
{
    int i, j, k, t = 0;
    for(i = 0; i < lb; i++)
    {
        for(t = j = 0; j < la; j++)
        {
            k = r[i + j] + b[i] * a[j] + t;
            r[i + j] = k % 10;
            t = k / 10;
        }
        if(t)
            r[i + j] = t;
    }
    lr = la + lb - 1;
    if(r[lr]) lr++;
}
big a, b, r;
char c[MS];
int main()
{
    int l, i, j, la, lb, lr;
    cin.getline(c, MS + 1);
    la = strlen(c);
    lb = la;
    for(i = 0; i < la; i++)
    {
        a[la - i - 1] = c[i] - '0';
    }
    cin.getline(c, MS + 1);
    for(i = 0; i < lb; i++)
    {
        b[lb - i - 1] = c[i] - '0';
    }
    multiplication(a, la, b, lb, r, lr);
    for(i = 0; i < lr; i++) cout << r[lr - i - 1];
    return 0;
}
