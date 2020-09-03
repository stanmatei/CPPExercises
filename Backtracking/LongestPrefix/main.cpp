#include <iostream>
#include <fstream>
#include <string.h>
#define MAXS 20
using namespace std;
ifstream in("prefix.in");
ofstream out("prefix.out");

char c[MAXS][MAXS], s[200];
int n, m, lmax, l;
int di[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void find_prefix(int i, int j)
{
    if(tolower(c[i][j]) == tolower(s[l]))
    {
        l++;
        for (int k = 0; k < 8; k++)
            find_prefix(i + di[k], j + dj[k]);
        l--;
    }
    else
    {
        if(l > lmax) lmax = l;
    }
}

int main()
{
    int i, j;
    in.get(s, sizeof(s));
    in >> n >> m;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            in.get(c[i][j]);
        }
        in.get();
    }
    for (i = 0; i <= n + 1; i++) c[i][0] = c[i][m + 1] = ' ';
    for (i = 0; i <= m + 1; i++) c[0][i] = c[n + 1][i] = ' ';

    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++){
            if(c[i][j] == s[0]){
                find_prefix(i, j);
            }
        }
    }
    s[lmax] = NULL;
    out << s;
    //for(i = 0; i < maxL; i++) out << s[i];
    return 0;
}
