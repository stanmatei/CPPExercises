#include <iostream>
#define MAXS 100
using namespace std;

int f, n, p[MAXS], v[MAXS];

void gen(int k)
{
    int i;
    for (i = 0; i < k; i++) cout << p[i] << " ";
    cout << endl;
    if(p[k - 1] <= f){
        for (i = f + 1; i <= n; i++){
            if(!v[i]){
                p[k] = i;
                v[i] = 1;
                gen(k + 1);
                v[i] = 0;
            }
        }
    }
    if(p[k - 1] > f){
        for (i = 1; i <= f; i++){
            if(!v[i]){
                p[k] = i;
                v[i] = 1;
                gen(k + 1);
                v[i] = 0;
            }
        }
    }

}

int main()
{
    int i;
    cin >> n >> f;
    for (i = 1; i <= f; i++){
        p[0] = i;
        v[i] = 1;
        gen(1);
        v[i] = 0;
    }
    for (i = f + 1; i <= n; i++){
        p[0] = i;
        v[i] = 1;
        gen(1);
        v[i] = 0;
    }

    return 0;
}
