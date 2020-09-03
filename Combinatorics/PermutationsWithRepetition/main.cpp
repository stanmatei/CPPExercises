#include <iostream>
#define MAXS 100
using namespace std;

int n, m[MAXS], s[MAXS], used[MAXS], p;

void gen(int k){
    if (k - 1 == p){
        for (int i = 1; i <= p; i++) cout << s[i] << " ";
        cout << endl;
    }
    else{
        for (int i = 1; i <= n; i++){
            if (used[i] < m[i]){
                used[i]++;
                s[k] = i;
                gen(k + 1);
                used[i]--;
            }
        }
    }
}


int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> m[i];
        p += m[i];
    }
    gen(1);
    return 0;
}
