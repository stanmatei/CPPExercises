#include <iostream>
#define MAXS 40
using namespace std;

int n, p, m[MAXS], sol[MAXS], no = 0;

void gen(int k){
    if (k == n + 1){
        cout << "Solution number: " << ++no << endl;
        for (int i = 1; i <= p; i++){
            for (int j = 1; j <= n; j++){
                if(sol[j] == i) cout << j << " ";
            }
            cout << endl;
        }
    }
    else{
        for (int i = 1; i <= p; i++){
            if (m[i] > 0){
                m[i]--;
                sol[k] = i;
                gen(k + 1);
                m[i]++;
            }
        }
    }
}

int main()
{
    cin >> n >> p;
    for (int i = 1; i <= p; i++) cin >> m[i];
    gen(1);
    return 0;
}
