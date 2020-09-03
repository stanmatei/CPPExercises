#include <iostream>
#include <fstream>
using namespace std;
ifstream in("king.in");
int di[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dj[] = {-1, 1, 2, 2, 1, -1, -2, -2};
int t[8][8], ih, jh, ik, jk;

int ok1, ok2, ok;

void gen(int i, int j){
    if (ok1 && ok2) ok = 1;
    else{
        cout << "......" << ok1 << "   " << ok2 << "........." << endl;
        for (int a = 0; a < 8; a++){
            for (int b = 0; b < 8; b++){
               cout << t[a][b] << " ";
            }
            cout << endl;
        }
        cout << endl;
        int k, i2, j2;
        for (k = 0; k < 8; k++){
            i2 = i + di[k];
            j2 = j + dj[k];
            if (i2 >= 0 && i2 < 8 && j2 < 8 && j2 >= 0){
                if (!t[i2][j2]){
                    t[i2][j2] = 1;
                    gen(i2, j2);
                    t[i2][j2] = 0;
                }
                if (t[i2][j2] == 3){
                    ok1 = 1;
                    t[i2][j2] = 1;
                    gen(i2, j2);
                    t[i2][j2] = 3;
                    ok1 = 0;
                }
                if (t[i2][j2] == 2 && ok1){
                    ok2 = 1;
                    t[i2][j2] = 1;
                    gen(i2, j2);
                    t[i2][j2] = 2;
                    ok2 = 0;
                }
            }
        }
    }
}

int main()
{
    int i, j;
    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            in >> t[i][j];
            if (t[i][j] == 2){
                ih = i;
                jh = j;
            }
            if (t[i][j] == 3){
                ik = i;
                jk = j;
            }
        }
    }
    gen(ih, jh);
    if (ok) cout << "yes";
    else cout << "no";
    return 0;
}
