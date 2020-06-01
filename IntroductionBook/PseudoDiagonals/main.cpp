#include <iostream>

using namespace std;
int a[100][100];
int main()
{
    int i, j, n, m, s = 0, d;
    cin>>n;
    cin>>m;
    for(i = 0; i < n; i++){
        for(j = 0;j < m; j++){
            cin>>a[i][j];
        }
    }
    for(d = 0; d < m - n + 1; d ++){
        s = 0;
        for(i = 0; i < n; i++) s += a[i][i + d];
        cout << s;
    }
    for(d = 0; d < m - n +1; d++){
        s = 0;
        for(i = 0; i < n; i++) s += a[i][m- i - d - 1];
        cout<<s;
    }
    return 0;
}
