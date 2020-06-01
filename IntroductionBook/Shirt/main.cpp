#include <iostream>
#include <iomanip>
#include <fstream>
#define MaxS 20
#define MaxSQ 400
using namespace std;
ifstream in("input.txt");


int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
struct Element{
    int r, c;
    unsigned d;
} q[MaxSQ], x, y;

int a[MaxS][MaxS], n, m, x0, y0, i, j, k, stQ, enQ;


int main()
{
    in >> n >> m;
    in >> x0 >> y0;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++) a[i][j] = -2;
    }
    while(in){
        in >> i >> j;
        a[i][j] = -1;
    }
    in.close();
    for(i = 1; i <= n; i++) a[i][0] = a[i][m + 1] = -1;
    for(j = 1; j <= m; j++) a[0][j] = a[n + 1][j] = -1;
    x.r = x0;
    x.c = y0;
    x.d = 0;
    a[x0][y0] = 0;
    q[stQ] = x;
    while(stQ <= enQ){
        x = q[stQ++];
        for(k = 0; k < 4; k++){
            y.r = x.r + dx[k];
            y.c = x.c + dy[k];
            if(a[y.r][y.c] == -2){
                y.d = x.d + 1;
                a[y.r][y.c] = y.d;
                q[++enQ] = y;

            }
        }
    }
    for(i = 0; i <= n + 1; i++){
        for(j = 0; j <= m + 1; j++){
            cout << setw(3) << a[i][j];
        }
        cout << endl;
    }
    return 0;
}
