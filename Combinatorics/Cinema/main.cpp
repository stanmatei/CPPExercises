#include <iostream>

using namespace std;

int n, p[50], temp[50], cpy[50];

int main()
{
    int i, j, k, aux, c;
    cin >> n;
    for (i = 1; i <= n; i++) cin >> p[i];
    int time = 0;
    int ok = 0;
    while (!ok){
        ok = 1;
        for (i = 1; i <= n; i++) temp[i] = 0;
        for (i = 1; i <= n; i++){
            if (p[i] != i && !temp[i]){
                temp[i] = 1;
                ok = 0;
                k = i;
                c = 1;
                cpy[c] = i;
                while (p[k] != i) {
                    k = p[k];
                    temp[k] = 1;
                    cpy[++c] = k;
                }
                for (j = 1; j <= c / 2; j++){
                    aux = p[cpy[j]];
                    p[cpy[j]] = p[cpy[c - j + 1]];
                    p[cpy[c - j + 1]] = aux;
                }
            }
        }
        if (!ok) time++;
    }
    cout << time;
    return 0;
}
