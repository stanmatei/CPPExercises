#include <iostream>
#include <fstream>
#include <string.h>
#define MAXS 100
using namespace std;
ifstream in("patches.in");
ofstream out("patches.out");
char cvs[MAXS][MAXS], sol[26];
int f[26];
int main()
{
    int m, n, i, j, h, l, ok, x, y, s = 0;
    char c;
    in >> n >> m;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            in >> cvs[i][j];
            f[cvs[i][j] - 'a']++;
        }
    }
    int maxi = 0;
    char r = 'a';
    for(i = 0; i < 26; i++){
        if(f[i] > maxi){
            maxi = f[i];
            r = i + 'a';
         }
    }
    out << r << endl;
    int done = 0;
    while(!done){
        done = 1;
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                c = cvs[i][j];
                if(c != 'w') done = 0;
                else {
                    l = j;
                    while(l < m && cvs[i][l] == 'w') l++;
                    if(l < m) c = cvs[i][l];
                }
                if(c != 'w'){
                    for(h = i; h < n && (cvs[h][j] == c || cvs[h][j] == 'w'); h++);
                    for(l = j; l < m && (cvs[i][l] == c || cvs[i][l] == 'w'); l++);
                    ok = 1;
                    for(x = i; x < h; x++){
                        for(y = j; y < l; y++){
                            if(cvs[x][y] != c && cvs[x][y] != 'w') ok = 0;
                        }
                    }
                    if(i > 0)
                        for(y = j; y < l; y++) if(cvs[i - 1][y] == c) ok = 0;
                    if(h < n)
                        for(y = j; y < l; y++) if(cvs[h][y] == c) ok = 0;
                    if(j > 0)
                        for(x = i; x < h; x++) if(cvs[x][j - 1] == c) ok = 0;
                    if(l < m)
                        for(x = i; x < h; x++) if(cvs[x][l ] == c) ok = 0;


                    if(ok){
                        cout << j <<" "<< l << " " << c << endl;
                        sol[s++] = c;
                        for(x = i; x < h; x++){
                            for(y = j; y < l; y++){
                                cvs[x][y] = 'w';
                            }
                        }
                    }
                }
            }
        }
    }
    i = 0;
    sol[s] = 'w';
    while(i < s / 2) {
        c = sol[i];
        sol[i] = sol[s - i];
        sol[s - i] = c;
        i++;
    }
    sol[++s] = NULL;
    out << sol;


    return 0;
}
