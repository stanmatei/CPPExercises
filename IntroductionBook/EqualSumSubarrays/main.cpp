#include <iostream>

using namespace std;
int a[101][51];
int main()
{
    int n, m, i, j, d;
    cin >> n;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            a[i][j] = n * i + j + 1;
        }
    }
    for(i = n; i < 2 * n -1; i++){
         for(j = 0; j < n; j++){
            a[i][j] = n * (i - n)  + j + 1;
        }
    }

    for(d = 0; d < n; d++){
        for(j = 0; j < n; j++){
            cout<<a[d + j][j]<<" ";
        }
        cout<< endl;
    }
    return 0;
}
