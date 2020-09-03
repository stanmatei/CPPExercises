#include <iostream>

using namespace std;

int a[100], n;

void doMerge(int p, int m, int q){
    int i = p, j =  m + 1, k = 0;
    int b[100];
    while(i <= m && j <= q){
        if(a[i] < a[j])
            b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    while(i <= m) b[k++] = a[i++];
    while(j <= q) b[k++] = a[j++];
    for(i = p; i <= q; i++) a[i] = b[i - p];
}

void mSort(int p, int q){
    if(q > p){
        int m = (q + p) / 2;
        mSort(p, m);
        mSort(m + 1, q);
        doMerge(p, m, q);
    }
}


int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    mSort(0, n - 1);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
