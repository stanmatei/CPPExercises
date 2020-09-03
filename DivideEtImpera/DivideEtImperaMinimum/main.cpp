#include <iostream>

using namespace std;

int a[1000];

int minimum(int p, int q){
    int m;
    if(q - p < 2){
        if(q == p) return a[p];
        return a[p] < a[q] ? a[p] : a[q];
    }
    else{
        m = (p + q) / 2;
        int m1, m2;
        m1 = minimum(p, m);
        m2 = minimum(m + 1, q);
        return m1 < m2 ? m1 : m2;
    }
}

int main()
{
    int n, i;
    cin >> n;
    for(i = 0; i < n; i++) cin >> a[i];
    cout << minimum(0, n - 1);
    return 0;
}
