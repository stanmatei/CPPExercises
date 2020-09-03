#include <iostream>
#define MAXS 1000
using namespace std;

int a[MAXS];

int divide(int p, int q){
    /*
    int x = a[q];
    int i, j, aux;
    i = p - 1;
    for(j = p; j < q; j++){
        if(a[j] <= x){
            i++;
            aux = a[i];
            a[i] = a[j];
            a[j] = aux;
        }
    }
    aux = a[i + 1];
    a[i + 1] = a[q];
    a[q] = aux;
    return i + 1;
    */
    int st = p, dr = q, x = a[p];
    while(st < dr){
        while(st < dr && a[dr] >= x) dr--;
        a[st] = a[dr];
        while(st < dr && a[st] <= x) st++;
        a[dr] = a[st];
        for(int j = p; j <= q; j++) cout << a[j] << " ";
        cout << endl;
    }
    a[st] = x;
    for(int j = p; j <= q; j++) cout << a[j] << " ";
        cout << endl;
    return st;
}

void qSort(int p, int q){
    int m = divide(p, q);
    if(m - 1 > p) qSort(p, m - 1);
    if(m + 1 < q) qSort(m + 1, q);
}


int main()
{
    int n, i;
    cin >> n;
    for(i = 0; i < n; i++) cin >> a[i];
    qSort(0, n - 1);
    for(i = 0; i < n; i++) cout << a[i] << endl;
    return 0;
}
