#include <iostream>

using namespace std;
int v[10000];
int main()
{
    int n, i, j, total, n_abs, start, sum;
    cin >> n;
    n_abs = n > 0 ? n : -n;
    total = 1;
    if(n > 0) v[n * 2 - 1] = 2 * n;
    else v[n * 2] = 2 * n - 1;
    for(i = 1; i <= n_abs / 2; i++){
        sum = i;
        for(j = i + 1; j <= n_abs / 2 + 1; j++) {
            sum += j;
            if(sum == n_abs){
                total += 2;
                v[n_abs + i - 1] = i + j;
                v[n_abs - i] = j - i + 1;
            }

        }
    }
    cout << total<<endl;
    for(i = 2 * n; i >= 0; i--){
        if(v[i])
            cout << n - i << " " << v[i] << endl;
    }


    return 0;
}
