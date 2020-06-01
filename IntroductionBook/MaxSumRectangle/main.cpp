#include <iostream>

using namespace std;
int a[100][100], sums[100][100];
int main()
{
    int n, m, i, j, k, l, xStart, yStart, xEnd, yEnd, sMax, sum_curr;
    cin >> n;
    cin >> m;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(i == 0 && j == 0) sums[0][0] =  a[0][0];
            if(i != 0 && j == 0) sums[i][j] = sums[i - 1][j] + a[i][j];
            if(i == 0 && j != 0) sums[i][j] = sums[i][j - 1] + a[i][j];
            if(i * j != 0){
                sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] + a[i][j];
            }
        }
    }
    sMax = a[0][0];
    xStart = yStart = xEnd = yEnd = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            for(k = i; k <n; k++){
                for(l = j; l < m; l++){
                    if(j == 0 && i == 0) sum_curr = sums[i][j];
                    if(i == 0 && j != 0) sum_curr = sums[k][l] - sums[k][j - 1];
                    if(i != 0 && j == 0) sum_curr = sums[k][l] - sums[i - 1][l];
                    if(i * j != 0) sum_curr = sums[k][l] - sums[k][j - 1] - sums[i - 1][l] + sums[i - 1][j - 1];
                    if(sum_curr == sMax){
                        if((xEnd - xStart + 1) * (yEnd - yStart + 1) < (k - i + 1) * (l - j + 1)){
                            xEnd = k;
                            yEnd = l;
                            xStart = i;
                            yStart = j;
                        }
                    }
                    if(sum_curr > sMax){
                        sMax = sum_curr;
                        xEnd = k;
                        yEnd = l;
                        xStart = i;
                        yStart = j;
                    }
                }
            }
        }
    }

    for(i = xStart; i <= xEnd; i++){
        for(j = yStart; j <= yEnd; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
