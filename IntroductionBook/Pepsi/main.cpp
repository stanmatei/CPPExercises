#include <iostream>
#include <fstream>

using namespace std;
ifstream in("pepsi.in");
ofstream out("pepsi.out");
int type[1000];
int v[100], finalV[100];
int sol[100];
int used[100], perm[100];

int main()
{
    int n, m, k, i, j, mini ,maxi, pos;
    char c;
    in >> n >> m >> k;
    for(i = 1; i <= n; i++){
        in >> c;
        if(c == 'R') type[i] = 1;
    }
    for(i = 1; i <= m; i++){
        v[i] = k;
        in >> finalV[i];
    }

    for(i = 1; i <= n; i++){
        if(type[i]){
            maxi = -1;
            for(j = 1; j <= m; j++){
                if(v[j] > maxi){
                    maxi = v[j];
                    pos = j;
                }
            }
            v[pos]--;
            sol[i] = pos;
        }
        else{
            mini = 1001;
            for(j = 1; j <= m; j++){
                if(v[j] < mini && v[j] > 0){
                    mini = v[j];
                    pos = j;

                }
            }
            v[pos]--;
            sol[i] = pos;
        }
    }
    for(i = 1; i <= m; i++){
        j = 1;
        while(finalV[i] !=  v[j] || used[j]) j++;
        used[j] = 1;
        perm[j] = i;
    }
    for(i = 1; i <= m; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    for(i = 1; i <= m; i++){
        cout << finalV[i] << " ";
    }
    cout << endl;
    for(i = 1; i <= m; i++){
        cout << perm[i] << " ";
    }
    for(i = 1; i <= n; i++) out << perm[sol[i]] << " ";


    return 0;
}
