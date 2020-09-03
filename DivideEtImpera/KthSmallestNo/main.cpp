#include <iostream>
#define MAXS 100
//find the Kth smallest number
using namespace std;

int n, k, a[MAXS];


int devide(int p, int q){
    int x = a[p], st = p, dr = q;
    while(st < dr){
        while(st < dr && a[dr] >= x) dr--;
        a[st] = a[dr];
        while(st < dr && a[st] <= x) st++;
        a[dr] = a[st];
    }
    a[st] = x;
    return st;
}

int findK(int p, int q){
    int m = devide(p, q);
    if(m < k - 1) return findK(m + 1, q);
    if(m > k - 1) return findK(p, m - 1);
    if(m == k - 1) return a[m];
}

int main()
{
    int i;
    cin >> n >> k;
    for(i = 0; i < n; i++) cin >> a[i];
    cout << findK(0, n - 1) << endl;
    for(i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
