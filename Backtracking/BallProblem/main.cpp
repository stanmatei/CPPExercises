#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream in("ball.in");
ofstream out("ball.out");

int di[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dj[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct pos{
    int i, j;
};
vector <pos> p;
int t[20][20], n, m;
int xb, yb;

void gen(int i, int j){
    if (i == 0 || i == n + 1 || j == 0 || j == m + 1){
        vector<pos>::iterator it;
        for (it =  p.begin(); it != p.end(); it++) cout << (*it).i << " " << (*it).j << " " << endl;
        cout << endl;
    }
    else{
        int k, i2, j2;
        pos a;
        for (k = 0; k < 8; k++){
            i2 = i + di[k];
            j2 = j + dj[k];
            if (t[i2][j2] < t[i][j]){
                a.i = i2;
                a.j = j2;
                p.push_back(a);
                gen(i2, j2);
                p.pop_back();
            }
        }
    }
}

int main()
{
    in >> n >> m;
    in >> xb >> yb;
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) in >> t[i][j];
    pos a;
    a.i = xb;
    a.j = yb;
    p.push_back(a);
    gen(xb, yb);
    return 0;
}
