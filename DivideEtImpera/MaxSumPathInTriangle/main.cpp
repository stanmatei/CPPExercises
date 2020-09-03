#include <iostream>

using namespace std;

int t[100][100], d[100], n, sol[100], s[100][100];

int divideAndConquer(int i, int j){
    if(i < n){
        int left_sum = divideAndConquer(i + 1, j);
        int right_sum = divideAndConquer(i + 1, j + 1);
        return t[i][j] + (right_sum < left_sum ? left_sum : right_sum);
    }
    return 0;
}
int iterative(){
    int i, j;
    int max_sum = 0, curr_sum = 0;
    while(d[n - 1] < n - 1){
        curr_sum = 0;
        for(i = 0; i < n; i++){
            curr_sum += t[i][d[i]];
        }
        if(curr_sum > max_sum) {
            max_sum = curr_sum;
            for(i = 0; i < n; i++)sol[i] = d[i];
        }
        int j = n - 1;
        while((d[j] == d[j - 1] + 1) && j >= 0) {
            j--;
        }
        int x = ++d[j];
        for(; j <= n - 1; j++) d[j] = x;
        for(i = 0; i < n; i++) cout << d[i] << " ";
        cout << endl;
    }
    curr_sum = 0;
    for(i = 0; i < n; i++){
        curr_sum += t[i][d[i]];
    }
    if(curr_sum > max_sum) {
        max_sum = curr_sum;
        for(i = 0; i < n; i++)sol[i] = d[i];
    }
    return max_sum;
}

int improvedIterative(){
    int i, j;
    for(i = 0; i < n; i++) s[n - 1][i] = t[n - 1][i];
    for(i = n - 1; i > 0; i--){
        for(j = 0; j < i; j++){
            s[i - 1][j] = s[i][j] > s[i][j + 1] ? s[i][j] : s[i][j + 1];
            s[i - 1][j]+= t[i - 1][j];
        }
    }
    return s[0][0];
}

int main()
{
    int i ,j;
    cin >> n;
    for(i = 0; i < n; i++)
        for(j = 0; j <= i; j++) cin >> t[i][j];
    cout << iterative() << " " << divideAndConquer(0, 0) << " " << improvedIterative();
    return 0;
}
