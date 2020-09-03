#include <iostream>
#define MAXS 100
using namespace std;
//generate all binary sequences of length m with n 1s
int b[MAXS], m, n, sum;

void gen(int k)
{
    if(k == m){
        if(sum == n){
            for (int i = 0; i < m; i++) cout << b[i] << " ";
            cout << endl;
        }
    }
    else
    {
        b[k] = 0;
        gen(k + 1);
        if(sum < n){
            sum++;
            b[k] = 1;
            gen(k + 1);
            sum--;
            b[k] = 0;
        }
    }
}

int main()
{
    cin >> m >> n;
    gen(0);
    return 0;
}
