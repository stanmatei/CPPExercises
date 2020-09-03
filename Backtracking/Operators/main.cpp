#include <iostream>
#define MAXS 100
using namespace std;
int n, total, a[MAXS];
char op[MAXS];

void gen(int k)
{
    int i;
    if(k == n - 1){
        for (i = 0; i < n - 1; i++){
            cout << a[i] << op[i];
        }
        cout << a[i] << endl;
    }
    else{
        total += a[k + 1];
        op[k] = '+';
        gen(k + 1);
        total -= a[k + 1];
        if(total - a[k + 1] > 0){
            total -= a[k + 1];
            op[k] = '-';
            gen(k + 1);
            total += a[k + 1];
        }
    }

}


int main()
{
    int i;
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
    total = a[0];
    gen(0);
    return 0;
}
