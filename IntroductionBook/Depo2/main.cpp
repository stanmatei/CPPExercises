#include <iostream>
#define MaxSize 101
using namespace std;
int st[MaxSize];
int main()
{
    int v, n, i;
    v = 0;
    cin >> n;
    if(n > MaxSize - 1) cout << "Too large!";
    else{
        for(i = 1; i <= n; i++) st[++v] = i;
        while(v) cout << st[v--] << " ";
    }

    return 0;
}
