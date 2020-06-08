#include <iostream>
#define MAXS 20
using namespace std;
int f[MAXS][MAXS];
int isValid(int (*v)[MAXS], int n, int m);
int isInjective(int (*v)[MAXS], int n, int m);
int isSurjective(int (*v)[MAXS], int n, int m);
int main()
{
    int n, m, x, y, i, j;
    cin >> n >> m;
    for(i = 0; i < n; i++){
        cin >> x >> y;
        f[x][y] = 1;
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    cout << isValid(f, n, m) << endl;
    cout << isInjective(f, n, m) << endl;
    cout << isSurjective(f, n, m) << endl;
    cout << (isInjective(f, n, m) == 1 && isSurjective(f, n, m) == 1) << endl;

    return 0;
}
int isValid(int (*v)[MAXS], int n, int m){
    int i, j, sum = 0, flag = 0;
    for(j = 0; j < n && !flag; j++){
        sum = 0;
        for(sum = i = 0; i < m; i++){
            sum += v[j][i];
        }
        if(sum > 1) flag = 1;
    }
    return !(flag == 1);
}

int isInjective(int (*v)[MAXS], int n, int m){
    int i, j, sum = 0, flag;
    for(flag = j = 0; j < m && !flag; j++){
        sum = 0;
        for(i = 0; i < n; i++){
            sum += v[i][j];
        }
        if(sum > 1) flag =1;
    }
    return !(flag == 1);
}

int isSurjective(int (*v)[MAXS], int n, int m){
    int i, j, sum = 0, flag;

    for(sum = flag = j = 0; j < m && !flag; j++){
            sum = 0;
        for(i = 0; i < n; i++){
            sum += v[i][j];
        }
        if(sum == 0) flag =1;
    }
    return !(flag == 1);
}
