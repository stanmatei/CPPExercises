#include <iostream>
#define MAXS 40
using namespace std;

int p1[MAXS], p2[MAXS], p3[MAXS], n, x = 1;


int main()
{
    int i, j, ok = 1;

    cin >> n;
    for (i = 1; i <= n; i++){
        cin >> p1[i];
        p2[i] = p3[i] = p1[i];
        if(p1[i] != i) ok = 0;
    }

    while(!ok){
        x++;
        ok = 1;
        for (i = 1; i <= n; i++){
            p1[i] = p3[p2[i]];
            if (p1[i] != i) ok = 0;
        }
        for (i = 1; i <= n; i++) p3[i] = p1[i];
    }
    cout << x;

    return 0;
}
