#include <iostream>

using namespace std;

int n, p[50], m, cycle[50], m1 = 1;

void gen(int k){
//cout << "Cycles: ";
//for (int i = 1; i <= n; i++) cout << cycle[i] << " ";
//cout << endl;
 if (k == n + 1){
    if (m1 == m){
        for (int i = 1; i <= n; i++) cout << p[i] << " ";
        cout << endl;
    }
 }
 else{
    int i, j, first, aux;
    if (n - k + 1 > m - m1){
        for (i = 1; i <= m1; i++){
            j = 1;
            while (cycle[j] != i) j++;
            first = j;
            cycle[k] = i;
            while (p[j] != first){
                //cout << "data " << k << ' ' << j << ' ' << p[j] << ' ' << p[p[j]] <<endl;
                aux = p[j];
                p[j] = k;
                p[k] = aux;
                gen(k + 1);
                p[j] = aux;
                j = p[j];
            }
            //cout << "data1 " << k << ' ' << j << ' ' << p[j] << endl;
            p[j] = k;
            p[k] = first;
            gen(k + 1);
            p[j] = first;
            cycle[k] = 0;
        }
    }
    if (m1 < m){
        p[k] = k;
        cycle[k] = ++m1;
        gen(k + 1);
        cycle[k] = 0;
        m1--;
    }
 }

}

int main()
{
    cin >> n >> m;
    p[1] = 1;
    cycle[1] = 1;
    gen(2);
    return 0;
}
