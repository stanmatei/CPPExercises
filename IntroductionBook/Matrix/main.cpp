#include <iostream>

using namespace std;
int m[100][100];
int main()
{
    int i, j, n;
    cin >> n;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i < j && i + j < n - 1) m[i][j] = 1;
            if(i > j && i + j < n - 1) m[i][j] = 2;
            if(i < j && i + j > n - 1) m[i][j] = 4;
            if(i > j && i + j > n - 1) m[i][j] = 3;
            if(i == j) m[i][j] = 0;
            if(i + j == n - 1) m[i][j] = 0;
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
