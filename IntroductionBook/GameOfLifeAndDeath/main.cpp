#include <iostream>
#include <fstream>
#define MAXS 100
using namespace std;
ifstream in("input.txt");
void next(void);
int pop1[MAXS][MAXS], pop2[MAXS][MAXS], n, m;
int d1[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, d2[8] = {0 , 1, 1, 1, 0, -1, -1, -1};
int main()
{
    int x = 1, i ,j;
    in >> n >> m;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            in >> pop1[i][j];
        }
    }
    while(x){
        next();
        cin >> x;
    }
    return 0;
}


void next(void){
    int i, j, nv, k;
    for(i = 1; i <= n ; i++){
        for(j = 1; j <= m; j++){
            for(nv = k = 0; k < 8; k++) nv += pop1[i + d1[k]][j + d2[k]];
            switch(nv){
                case 2:
                    pop2[i][j] = pop1[i][j];
                    if(pop2[i][j]) cout << "* ";
                    else cout << "  ";
                    break;
                case 3:
                    pop2[i][j] = 1;
                    cout << "* ";
                    break;
                default:
                    pop2[i][j] = 0;
                    cout << "  ";
                    break;
            }
        }
        cout << endl;
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++) pop1[i][j] = pop2[i][j];
    }

}
