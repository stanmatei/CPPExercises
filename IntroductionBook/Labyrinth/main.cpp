#include <iostream>
#include <fstream>
#define MAXS 20
#define MAXQ 400
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");
int d1[4] = {-1, 0, 1, 0}, d2[4] = {0, 1, 0, -1};
struct Element
{
    int i, j, d, val, iP, jP;
} q[MAXQ], x, y, parent[MAXS][MAXS];

int v= -1, a[MAXS][MAXS], s, e = -1, k, b[MAXS][MAXS];
char p[MAXQ];
int main()
{
    int n, m, i, j;
    in >> n >> m;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            in >> a[i][j];
        }
    }
    x.i = 0;
    x.j = 0;
    x.d = 0;
    x.val = 0;
    q[++e] = x;

    while(s <= e)
    {
        x = q[s++];
        for(k = 0; k < 4; k++)
        {
            y.i = x.i + d1[k];
            y.j = x.j + d2[k];
            if(y.i >= 0 && y.i < n && y.j >=0 && y.j < m)
            {

                if((a[y.i][y.j] == (x.val + 1)) || (a[y.i][y.j] == 1 && x.val == 4) || a[y.i][y.j] == 0)
                {
                    y.val = a[y.i][y.j];
                    y.d = x.d + 1;
                    q[++e] = y;
                    parent[y.i][y.j] = x;
                    b[y.i][y.j] = y.d;

                }

            }
            a[x.i][x.j] = -1;
        }
    }

    out << b[n - 1][m - 1] << endl;
    x.i = n - 1;
    x.j = m - 1;
    x.d = b[n - 1][m - 1];
    x.val = 0;
    y = parent[x.i][x.j];
    cout << x.d;
    while(x.d != 0){
        if(x.i - y.i == -1){
            p[++v] = 'U';
        }
        if(x.i - y.i == 1){
            p[++v] = 'D';
        }
        if(x.j - y.j == -1){
            p[++v] = 'L';
        }
        if(x.j - y.j == 1){
            p[++v] = 'R';
        }
        x = y;
        y = parent[x.i][x.j];
    }
    while(v >= 0){
        out << p[v--];
    }

    return 0;
}
