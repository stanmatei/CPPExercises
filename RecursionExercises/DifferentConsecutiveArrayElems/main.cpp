#include <iostream>
#define MAX 100
using namespace std;
int a[MAX], n, i;

int consecutive(){
    if(i == n - 1) return 1;
    if(a[i] != a[++i] && consecutive()) return 1;
    return 0;
}

int main()
{
    cin >> n;
    for(int j = 0; j < n; j++) cin >> a[j];
    cout << consecutive();
    return 0;
}
