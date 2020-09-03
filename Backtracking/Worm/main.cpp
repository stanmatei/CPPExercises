#include <iostream>
#include <fstream>
using namespace std;
ifstream in("worm.in");
int n, m, t[101][101], cost, vi[101][101], s, smax = -1, found, to_find, ok;
struct pos{
    int i, j, sn;
} p[1000];
int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};
int v[1000], r[1000], sol[1000];
void eat(int i, int j){
    if (found == to_find) {
        ok = 1;
        if (s > smax) smax = s;
    }
    cout << "...." << s << "...." << found << endl;
    for (int a = 1; a <= n; a++){
        for (int b = 1; b <= m; b++){
           cout << vi[a][b] << " ";
        }
        cout << endl;
    }
    cout << endl;
    if (found < to_find){
        int k, i2, j2;
        if (s - cost >= 0){
            s -= cost;
            for (k = 0; k < 4; k++){
                i2 = i + di[k];
                j2 = j + dj[k];
                if (t[i2][j2] >= 0 && !vi[i2][j2]){
                    found += 1 * (t[i2][j2] != 0);
                    vi[i2][j2] = 1;
                    s += t[i2][j2];
                    eat(i2, j2);
                    found -= 1 * (t[i2][j2] != 0);
                    vi[i2][j2] = 0;
                    s -= t[i2][j2];

                }
            }
            s += cost;
        }
    }
}

int abs (int x){
    if (x < 0) return -x;
    return x;
}

void gen (int k){
    int i, j;
    cout << s << endl;
    if (k == n){
        if (s >= smax){
            smax = s;
            for (i = 0; i < n; i++) sol[i] = r[i];
        }
    }
    else {
        for (i = 0; i < n; i++){
            if (s - (abs(p[r[k - 1]].i - p[i].i) + abs(p[r[k - 1]].j - p[i].j)) >= 0){
                if (!v[i]){
                    s -= (abs(p[r[k - 1]].i - p[i].i) + abs(p[r[k - 1]].j - p[i].j));
                    s += p[i].sn;
                    r[k] = i;
                    v[i] = 1;
                    gen(k + 1);
                    v[i] = 0;
                    s -= p[i].sn;
                    s += (abs(p[r[k - 1]].i - p[i].i) + abs(p[r[k - 1]].j - p[i].j));
                }
            }
        }
    }
}

int main()
{
    /*
    int i, j;
    in >> n >> m;
    in >> cost;
    while (!in.eof()){
        in >> i >> j;
        in >> t[i][j];
        to_find++;
    }
    to_find--;
    for (i = 0; i <= n + 1; i++) t[i][0] = t[i][m + 1] = -1;
    for (j = 0; j <= m + 1; j++) t[0][j] = t[n + 1][j] = -1;
    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++){
            if (t[i][j]){
                vi[i][j] = 1;
                s = t[i][j];
                found = 1;
                eat(i, j);
                v[i][j] = 0;
            }
        }
    }
    if (ok) cout << smax;
    else cout << "the worm couldn't find all the food";
    */
    n = 0;
    while (!in.eof())   in >> p[n].i >> p[n].j >> p[n++].sn;
    n--;
    cout << "..." << n << endl;
    gen(0);
    if (smax >= 0) cout << smax;
    else cout << "impossible";

    return 0;
}
