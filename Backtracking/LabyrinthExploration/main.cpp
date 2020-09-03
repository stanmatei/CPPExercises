#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream in("explore.in");

int n, m;
int t[20][20];

int di[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dj[] = {0, 1, 1, 1, 0, -1, -1, -1};
struct pos{
    int i,j;
}v;
vector<pos> p, e;
void explore(int i, int j){
    int k, i2, j2;
    pos a;
    for (k = 0; k < 8; k++){
        i2 = i + di[k];
        j2 = j + dj[k];
        if (!t[i2][j2]){
            a.i = i2;
            a.j = j2;
            t[i2][j2] = 2;
            e.push_back(a);
            explore(i2, j2);
            t[i2][j2] = 0;
        }
    }
}

int main()
{
    in >> n >> m;
    int x, y;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            in >> t[i][j];
            if (t[i][j] == 2){
                x = i;
                y = j;
            }
        }
    explore(x, y);
    vector<pos>::iterator it;
    for (it = e.begin(); it != e.end(); it++) cout << (*it).i << " " << (*it).j << endl;
    return 0;
}
