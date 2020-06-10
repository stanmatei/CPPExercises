#include <iostream>

using namespace std;
int t[100][100];
int combinationsRecursive(int n, int k){
    if(n == k || k == 0) return 1;
    return combinationsRecursive(n - 1, k) + combinationsRecursive(n - 1, k - 1);
}

void pascalTriangle(int n){
    int i, k;
    t[0][0] = 1;
    for(i = 1; i < n; i++){
        t[i][0] = 1;
        t[i][i] = 1;
        for(k = 1; k <= i - 1; k++){
            t[i][k] = t[i - 1][k - 1] + t[i - 1][k];
        }
    }
    for(i = 0; i < n; i++){
        for(k = 0; k <= i; k++) cout << t[i][k]<< " ";
        cout << endl;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    pascalTriangle(n + 1);
    cout << combinationsRecursive(n, k) << endl;
    cout << t[n][k];
    return 0;
}
