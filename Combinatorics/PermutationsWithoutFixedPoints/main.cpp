#include <iostream>

using namespace std;

int n, p[30], used[30];

void gen(int k){
    if (k - 1== n){
        for (int i = 1; i <= n; i++) cout << p[i];
        cout << endl;
    }
    else {
        for (int i = 1; i <= n; i++){
            if (!used[i] && k != i){
                used[i] = 1;
                p[k] = i;
                gen(k + 1);
                used[i] = 0;
            }
        }
    }

}

int main()
{
    cin >> n;
    gen(1);
    return 0;
}
