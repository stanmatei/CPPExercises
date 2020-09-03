#include <iostream>

using namespace std;

int x, y, n, p[30], used[30];

void gen(int k){
    if (k == n + 1){
        for (int i = 1; i <= n; i++) cout << p[i] << ' ';
        cout << endl;
    }
    else {
        for (int i = 1; i <= n; i ++){
            if (!used[i]){
                if (i == y && used[x] || i != y){
                    used[i] = 1;
                    p[k] = i;
                    gen(k + 1);
                    used[i] = 0;
                }
            }
        }
    }

}

int main()
{
    cin >> n >> x >> y;
    gen(1);
    return 0;
}
