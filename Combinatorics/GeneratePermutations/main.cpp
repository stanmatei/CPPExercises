#include <iostream>
#define MAXS 100
using namespace std;

int p[MAXS], used[MAXS + 1], n;

void gen(int k){
    if (k == n){
        for (int i = 0; i < n; i++) cout << p[i] << " ";
        cout << endl;
    }
    else {
        for (int i = 1; i <= n; i++){
            if (!used[i]){
                p[k] = i;
                used[i] = 1;
                gen(k + 1);
                used[i] = 0;
            }
        }
    }
}

int main()
{
    cin >> n;
    gen(0);
    return 0;
}
