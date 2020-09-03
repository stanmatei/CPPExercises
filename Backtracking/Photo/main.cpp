#include <iostream>
#include <fstream>
#define MAXS 20
using namespace std;
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
int p[MAXS][MAXS], m, n, sum;
ifstream in("photo.in");
ofstream out("photo.out");

void del_object(int i, int j)
{
    p[i][j] = 0;
    for(int d = 0; d < 4; d++){
        if(p[i + di[d]][j + dj[d]]){
            del_object(i + di[d], j + dj[d]);
        }
    }
}


int main()
{
    int i, j;
    in >> n >> m;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) in >> p[i][j];
    in.close();
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if(p[i][j]){
                del_object(i, j);
                sum++;
            }
        }
    }
    out << "Number of objects: " << sum;
    out.close();
    return 0;
}
