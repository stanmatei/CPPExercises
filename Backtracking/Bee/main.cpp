#include <iostream>
#include <fstream>
#define MAXS 30
#define infinity 10000
using namespace std;

ifstream in("bee.in");
ofstream out("bee.out");

int a[MAXS][MAXS], t[MAXS][MAXS], r, k, n, m, h1, h2;
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};


void pollenize(int i, int j)
{
    int ni, nj;
    t[i][j] = 1;
    cout << i << " " << j << endl;
    for (int d = 0; d < 4; d++)
    {
        ni = i + di[d];
        nj = j + dj[d];
        if(!t[ni][nj])
        {
            if(a[i][j] >= a[ni][nj] &&
                a[i][j] - a[ni][nj] <= h2) pollenize(ni, nj);
            else if(a[i][j] < a[ni][nj] &&
                a[ni][nj] - a[i][j] <= h1) pollenize(ni, nj);
        }

    }
}

int area()
{
    int i, j, p, q, i1, j1, Max = 0, flag;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if(t[i][j])
            {
                for (p = i; p <= n; p++)
                    for (q = j; q <= m; q++)
                        if(t[p][q])
                        {
                            flag = 1;
                            for (i1 = i; i1 <= p; i1++)
                                for (j1 = j; j1 <= q; j1++) flag *= t[i1][j1];
                            if(flag)
                                if ((p - i + 1) * (q - j + 1) > Max) Max = (p - i + 1) * (q - j + 1);
                        }
            }
    return Max;
}


int main()
{
    in >> n >> m >> k >> r >> h1 >> h2;
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) in >> a[i][j];

    for (i = 0; i <= n + 1; i++) a[i][0] = a[i][m + 1] = infinity;
    for (i = 0; i <= m + 1; i++) a[0][i] = a[n + 1][i] = infinity;
    pollenize(k, r);
    out << area();

    return 0;
}
