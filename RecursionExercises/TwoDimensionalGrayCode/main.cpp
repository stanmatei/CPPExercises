#include <iostream>

#define MAX 10
#define MAX2 (1 << MAX)

using namespace std;

int line[1 << MAX][MAX];
int columns[1 << MAX][MAX];
int grid[1 << MAX][1 << MAX];
int n, m;

void genLines(int);
void genColumns(int);

int main()
{
    int i, j, k, l;

    cin >> m >> n;
    genLines(m);
    genColumns(n);
    for(i = 0; i < 1 << m; i++){
        for(j = 0; j < 1 << n; j++){
            for(k = 0; k < m; k++){
                grid[i][j] += (1 << k) * line[i][k];
            }
            for(k = 0; k < n; k++){
                grid[i][j] += (1 << (m + k)) * columns[j][k];
            }
        }
    }
    for(i = 0; i < (1 << n); i++){
        for(j = 0; j < 1 << n; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


void genLines(int k){

    if(k == 1){
        line[1][0] = 1;
    }
    else{
        int i, j;
        genLines(k - 1);
        for(i = (1 << (k - 1)) - 1; i >= 0; i--){
            for(j = 0; j < k - 1; j++)
                line[(1 << k) - i - 1][j]  = line[i][j];
            line[(1 << k) - i - 1][k - 1] = 1;
        }
    }
}


void genColumns(int k){
    if(k == 1) columns[1][0] = 1;
    else{
        genColumns(k - 1);
        int i, j;
        for(i = (1 << (k - 1)) - 1; i >= 0; i--){
            for(j = 0; j < k - 1; j++){
                columns[(1 << k) - i - 1][j] = columns[i][j];
            }
            columns[(1 << k) - i  - 1][j] = 1;
        }
    }
}
