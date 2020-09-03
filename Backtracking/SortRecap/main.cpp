#include <iostream>
#define MAXS 100
using namespace std;
int f[MAXS], n;

void do_merge(int p, int m, int q){
    int i = p, j = m + 1, k = 0, a[MAXS];
    while (i <= m && j <= q){
        if(f[i] < f[j]){
          a[k++] = f[i];
          i++;
        }
        else{
            a[k++] = f[j];
            j++;
        }
    }
    for(; i <= m; i++) a[k++] = f[i];
    for(; j <= q; j++) a[k++] = f[j];
    for(k = 0; k < n; k++) f[i + k] = a[k];
}

void m_sort(int i, int j){
    if(j > i){
        int m = (i + j) / 2;
        m_sort(i, m);
        m_sort(m + 1, j);
        do_merge(i, m, j);

    }
}
int divide(int p, int q){
    /*
    int i, j, aux, x = f[q];
    i = p - 1;
    for(j = p; j < q; j++){
        if(f[j] <= x){
            i++;
            aux = f[i];
            f[i] = f[j];
            f[j] = aux;
        }
    }
    aux = f[i + 1];
    f[i + 1] = x;
    f[q] = aux;
    return i + 1;
    */
    int st = p, dr = q, x = f[p];
    while(st < dr){
        while(st < dr && f[dr] >= x) dr--;
        f[st] = f[dr];
        while(st < dr && f[st] <= x) st ++;
        f[dr] = f[st];
    }
    a[st] = x;
    return st;
}

void q_sort(int p, int q){
    if(p < q){
        int m = divide(p, q);
        if(m - 1 > p) q_sort(p, m - 1);
        if(m + 1 < q) q_sort(m + 1, q);
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
