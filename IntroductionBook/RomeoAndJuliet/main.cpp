#include <iostream>
#include <fstream>
#include <string.h>
#define MAXS 20
#define MAXQ 400
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
struct Element{
    int i, j, d;
}q[MAXQ], x, y;
int d1[8] = {-1, -1, 0 ,1, 1, 1, 0, -1}, d2[8] = {0, 1, 1, 1, 0, -1, -1, -1};
char a[MAXS][MAXS];
int b[MAXS][MAXS], c[MAXS][MAXS], s, e = -1, ri, rj, ji, jj;
int main()
{
    int n, m, i ,j, k;
    in >> n >> m;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            in.get(a[i][j]);
            if(a[i][j] == '\n') in.get(a[i][j]);
            cout<< a[i][j] << " ";
            if(a[i][j] == 'R'){
                ri = i;
                rj = j;
            }
            if(a[i][j] == 'J'){
                ji = i;
                jj = j;
            }
        }
        cout << endl;
    }

    x.i = ri;
    x.j = rj;
    x.d =0;
    q[++e] = x;
    while(s <= e){
        x = q[s++];
        cout<< x.d << endl;
        for(k = 0; k < 8; k++){
            y.i = x.i + d1[k];
            y.j = x.j + d2[k];
            if(y.i >= 0 && y.i < n && y.j >=0 && y.j < m){
                if(a[y.i][y.j] == '_'){
                    y.d = x.d + 1;
                    b[y.i][y.j] = y.d;
                    a[y.i][y.j] = '*';
                    q[++e] = y;
                }
            }

        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(a[i][j] == '*') a[i][j] = '_';
            cout<< b[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
    s = 0;
    e = -1;

    x.i = ji;
    x.j = jj;
    x.d =0;
    q[++e] = x;
    while(s <= e){
        x = q[s++];
        for(k = 0; k < 8; k++){
            y.i = x.i + d1[k];
            y.j = x.j + d2[k];
            if(y.i >= 0 && y.i < n && y.j >=0 && y.j < m){
                if(a[y.i][y.j] == '_'){
                    y.d = x.d + 1;
                    c[y.i][y.j] = y.d;
                    a[y.i][y.j] = '*';
                    q[++e] = y;
                }
            }

        }
    }

     for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            cout<< a[i][j]<<" ";
        }
        cout << endl;
    }
    cout <<endl;

    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            cout<< c[i][j]<<" ";
        }
        cout << endl;
    }


    int mini = 401, i0 = 0, j0 = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if((b[i][j] == c[i][j]) && b[i][j] != 0){
                cout <<"da";
                if(b[i][j] < mini){
                    mini = b[i][j];
                    i0 = i;
                    j0 = j;
                }
            }
        }
    }
    out << mini << " " << i0 << " " << j0;


    return 0;
}
