#include <iostream>
#include <fstream>
using namespace std;
ifstream in("aquarium.in");
int t[31][31], p[31], kmax, smax, s, n, r[31], sol[31], total;

void gen(int k){
    if (k <= n){
        int i, j, ok;
        for (i = sol[k - 1] + 1; i <= n; i++){
            ok = 1;
            for (j = 1; j <= k; j++)
                if (t[i][j]) ok = 0;
            if (ok){
                if (total + p[i] <= s){
                    total += p[i];
                    r[k] = i;
                    if (k  > kmax) {
                        for (j = 1; j <= k; j++) sol[j] = r[j];
                        kmax = k;
                        smax = total;
                    }
                    if (k == kmax && total > smax){
                        for (j = 1; j <= k; j++) sol[j] = r[j];
                        kmax = k;
                        smax = total;
                    }
                    gen(k + 1);
                    total -= p[i];
                }
            }
        }
    }
}

int main()
{
    int i, j;
    in >> n >> s;
    for (int k = 1; k < n; k++) in >> p[k];
    while (!in.eof()){
        in >> i >> j;
        t[i][j] = 1;
        t[j][i] = 1;
    }
    gen(0);
    cout << kmax << " " << smax << endl;
    for (i = 1; i <= kmax; i++) cout << sol[i] << " ";
    return 0;
}
