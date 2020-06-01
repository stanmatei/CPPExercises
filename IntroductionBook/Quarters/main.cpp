#include <iostream>

using namespace std;

int v[100][100];

int main()
{
    int n, i ,j;
    //n is an uneven number
    cin >> n;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i < n/2 && j < n/2) v[i][j] = 2;
            if(i > n/2 && j < n/2) v[i][j] = 3;
            if(i < n/2 && j > n/2) v[i][j] = 1;
            if(i > n/2 && j > n/2) v[i][j] = 4;
            if(i == n/2 || j == n/2) v[i][j] = 0;
            cout<<v[i][j]<<" ";
        }
        cout<< endl;
    }
    return 0;
}
