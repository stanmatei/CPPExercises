#include <iostream>
#define MAXDIG 10
using namespace std;
long int n, k, total = 0;
long int c[MAXDIG], p10[MAXDIG];
int main()
{
    int i, first;
    cin >> n >> k;
    c[0] = 0;
    p10[0] = 1;
    for(i = 1; i < MAXDIG; i++){
        c[i] = 9 * c[i - 1] + p10[i - 1];
        p10[i] = 10 * p10[i - 1];
    }
    for(i = MAXDIG - 1; i >= 0; i--){
        if(n >= p10[i]){
            first = n / p10[i];
            if(first < k){
                total += first * c[i];
            }
            if(first == k){
                total += first * c[i];
                total += n % p10[i] + 1;
                break;
            }
            if(first > k){
                total += (first - 1) * c[i];
                total += p10[i];
            }
            n %= p10[i];

        }
    }
    cout << total;
    return 0;
}
