#include <iostream>

using namespace std;

int n, a[100], s = 0;

void doMerge(int p, int m, int q){
    int i = p, k = 0, j = m + 1;
    int b[100];
    while(i <= m && j <= q){
        if(a[i] < a[j]){
            b[k++] = a[i++];
        }
        else{
            s += (m - i + 1);
            b[k++] = a[j++];
        }
    }
    while(i <= m) b[k++] = a[i++];
    while(j <= q) b[k++] = a[j++];
    for(i = p; i <= q; i++){
        a[i] = b[i - p];
    }
}


void mSort(int p, int q){
    if(p < q){
        int m = (q + p) / 2;
        mSort(p, m);
        mSort(m + 1, q);
        doMerge(p, m, q);
    }
}

int main()
{
    int i;
    cin >> n;
    for(i = 0; i < n; i++) cin >> a[i];
    mSort(0, n - 1);
    cout << s;
    return 0;
}
