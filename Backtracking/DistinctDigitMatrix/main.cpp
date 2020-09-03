#include <iostream>
#include <fstream>
#define MAXS 11
using namespace std;

int m[MAXS][MAXS], n;
int line[MAXS][11], col[MAXS][11];

void gen(int i, int j){
    if(i == n){
        for (int i1 = 0; i1 < n; i1++){
            for (int j1 = 0; j1 < n; j1++) cout << m[i1][j1] << " ";
            cout << endl;
        }
        cout << endl;
    }
    else{
        if(j == n){
            gen(i + 1, 0);
        }
        else{
            int p, q;
            for (p = 1; p <= n; p++){
                if(!line[i][p] && !col[j][p]){
                    if(i == 0 && m[i][j - 1] % 2 != p % 2){
                        m[i][j] = p;
                        line[i][p] = 1;
                        col[j][p] = 1;
                        gen(i, j + 1);
                        line[i][p] = 0;
                        col[j][p] = 0;
                    }
                    if(i > 0 && m[i - 1][j] % 2 != p % 2){
                        m[i][j] = p;
                        line[i][p] = 1;
                        col[j][p] = 1;
                        gen(i, j + 1);
                        line[i][p] = 0;
                        col[j][p] = 0;
                    }
                }
            }
        }
    }
}

void gen_first(){

}



int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++){
        m[0][0] = i;
        line[0][i] = 1;
        col[0][i] = 1;
        gen(0, 1);
        line[0][i] = 0;
        col[0][i] = 0;
    }

    return 0;
}
