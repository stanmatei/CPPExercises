#include <iostream>
#include <fstream>
#define MAXS 20
using namespace std;

ifstream in("lab.in");
ofstream out("lab.out");

int l[MAXS][MAXS], n, m, xs, ys, xb, yb, nSol;
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};


void boarding()
{
    int i, j;
    for (i = 0; i <= m + 1; i++) l[0][i] = l[n + 1][i] = 1;
    for (j = 0; j <= n + 1; j++) l[j][0] = l[j][m + 1] = 1;
}

void find_path(int x, int y)
{
    int i, j;
    l[x][y] = 2;
    if(x == xb && y == yb)
    {
        out << "Solution: " << ++nSol << endl;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++) out << l[i][j] << " ";
            out << endl;
        }
    }
    else
    {
        for (int d = 0; d < 8; d++)
        {
            if(!l[x + dx[d]][y + dy[d]])
                find_path(x + dx[d], y + dy[d]);
        }
    }
    l[x][y] = 0;

}

int main()
{
    int i, j;
    in >> n >> m >> xs >> ys >> xb >> yb;
    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++) in >> l[i][j];
    }
    in.close();
    boarding();
    find_path(xs, ys);
    if(!nSol) out << "no solution found";
    out.close();
    return 0;
}
