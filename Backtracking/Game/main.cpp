#include <iostream>
#include <fstream>
using namespace std;
ifstream in("game.in");
int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

char t[20][20];
int p[20][20];
int v[26];
int maxi, sum;
int n, m;

void gen(int i, int j){
    int k, i2, j2, ok = 0;
    for (k = 0; k < 4; k++){
        i2 = i + di[k];
        j2 = j + dj[k];
        if (i2 < n && i2 >= 0 && j2 < m && j2 >= 0){
            if (!p[i2][j2] && !v[t[i2][j2] - 'A']){
                p[i2][j2] = 1;
                v[t[i2][j2] - 'A'] = 1;
                sum += 1;
                gen(i2, j2);
                sum -= 1;
                p[i2][j2] = 0;
                v[t[i2][j2] - 'A'] = 0;
                ok = 1;
            }
        }
    }
    if (!ok){
        if (sum > maxi) maxi = sum;
    }
}
int main()
{
    in >> n >> m;
    int i, j;
    in.get();
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            in.get(t[i][j]);
        }
        in.get();
    }
    v[t[0][0] - 'A'] = 1;
    p[0][0] = 1;
    sum += 1;
    gen(0, 0);
    cout << maxi;
    return 0;
}
