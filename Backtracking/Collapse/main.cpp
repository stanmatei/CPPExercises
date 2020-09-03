#include <iostream>
#include <fstream>
#define Dmax 52
using namespace std;

ifstream in("collapse.in");
ofstream out("collapse.out");
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
int n, m, clickNo, maxL, minC;
struct pos
{
    char c;//colour
    int gr;//group number
};

pos t[Dmax][Dmax];
int find_max_group();
int det_group(int, int, int, char);
void del_group(int, int, int);
void remake_table(int, int);

int det_group(int grNo, int i, int j, char ch)
{
    int sum = 1, k;
    if(t[i][j].c != ch) return 0;
    t[i][j].gr = grNo;
    for (k = 0; k < 4; k++){
        if(t[i + di[k]][j + dj[k]].gr == 0) sum += det_group(grNo, i + di[k], j + dj[k], ch);
    }
    return sum;

}

int find_max_group()
{
    int maxDim = 0, dim, grNo = 1, i, j;
    for (j = 1; j <= m; j++){
        for (i = n; i >= 1; i--)
            if(t[i][j].gr == 0 && t[i][j].c != ' ')
            {
                dim = det_group(grNo, i, j, t[i][j].c);
                if(dim > maxDim){
                    maxDim = dim; maxL = i; minC = j;
                }
                else if (dim == maxDim){
                    if(j < minC){
                        minC = j; maxL = i;
                    }
                    else if(j == minC && i > maxL) maxL = i;
                }
                grNo++;
            }
    }
    return maxDim;
}
void del_group(int grNo, int i, int j)
{
    if(t[i][j].gr == grNo && t[i][j].c != ' '){
        t[i][j].c = ' ';
        del_group(grNo, i - 1, j);
        del_group(grNo, i, j + 1);
        del_group(grNo, i + 1, j);
        del_group(grNo, i, j - 1);
    }
}

void remake_table(int line, int col)
{
    int i, j, i2, j2;
    del_group(t[line][col].gr, line, col);
    for (j = 1; j <= m; j++){
        for (i = n; i >= 1; i--){
            if(t[i][j].c == ' '){
                for (i2 = i - 1; i2 >= 1 && t[i2][j].c == ' '; i2--);
                if(i2){
                    t[i][j] = t[i2][j]; t[i2][j].c = ' ';
                }
                else break;
            }
        }
    }
    for (j = 1; j <= m; j++){
        if(t[n][j].c == ' '){
            for (j2 = j + 1; j2 <= m && t[i][j2].c == ' '; j2++);
            if(j2 < m + 1){
                for (i = 1; i <= n; i++){
                    t[i][j] = t[i][j2];
                    t[i][j].c = ' ';
                }
            }
            else break;
        }
    }
    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++){
            t[i][j].gr = 0;
        }
    }

}

int main()
{
    int s, i, j, dim;
    in >> n >> m;
    in.get();
    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++) in >> t[i][j].c;
        in.get();
    }
    for (i = 0; i <= m + 1; i++) t[0][i].gr = t[n + 1][i].gr = Dmax * Dmax + 1;
    for (i = 0; i <= n + 1; i++) t[i][0].gr = t[i][m + 1].gr = Dmax * Dmax + 1;

    do{
        maxL = 0;
        minC = m + 1;
        dim = find_max_group();
        if(dim > 1){
            clickNo++;
            remake_table(maxL, minC);
        }
        cout << clickNo << endl;

    }while(dim > 1);
    out << clickNo << endl;

    return 0;
}
