#include <iostream>
#define MAXS 40
using namespace std;

int primes[1001], n, sol[MAXS], s;

void sieve(){
    int d;
    int i;
    primes[1] = 1;
    for (i = 2; i <= 1000; i++){
        if (!primes[i]){
            d = i;
            while(d + i < 1000){
                d += i;
                primes[d] = 1;
            }
        }
    }
}

void gen(int k){
    if (s >= n){
        if (s == n){
            cout << n << " = ";
            for (int i = 0; i < k - 1; i++) cout << sol[i] << " + ";
            cout << sol[k - 1] << endl;
        }
    }
    else{
        int i;
        for (i = sol[k - 1] + 1; i <= n - s; i++){
            if (!primes[i]){
                    sol[k] = i;
                    s += i;
                    gen(k + 1);
                    s -= i;
            }
        }
    }
}

int main()
{
    cin >> n;
    sieve();
    for (int i = 1; i <= n; i++){
        if (!primes[i]){
            sol[0] = i;
            s += i;
            gen(1);
            s -= i;
        }
    }
    return 0;
}
