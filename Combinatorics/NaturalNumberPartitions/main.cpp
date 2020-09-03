#include <iostream>
#define MAXS 30
using namespace std;

int p[MAXS], n, sum;

void gen(int k){
    if (sum == n){
        cout << n << " = ";
        for (int i = 1; i < k - 1; i++) cout << p[i] << " + ";
        cout << p[k - 1] << endl;
    }
    else {
        for (int i = p[k - 1]; i <= n - sum; i++){
            p[k] = i;
            sum += i;
            gen(k + 1);
            sum -= i;
        }
    }
}

int main()
{
    cin >> n;
    p[0] = 1;
    gen(1);
    return 0;
}
