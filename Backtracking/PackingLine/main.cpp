#include <iostream>
#include <fstream>
#define MAXS 100
using namespace std;
ifstream in("band.in");
ofstream out("band.out");

int g[MAXS], n, gmax, mini = MAXS, t1, t2, c;

void gen(int k){

    int aux;
    if(c < mini){
        if(k == n){
            if(c < mini) mini = c;
        }
        else
        {
            if(t1 + g[k] <= gmax){
                t1 += g[k];
                gen(k + 1);
                t1 -= g[k];
            }

            if(t2 + g[k] <= gmax){
                t2 += g[k];
                gen(k + 1);
                t2 -= g[k];
            }

            aux = t2;
            t2 = g[k];
            c++;
            gen(k + 1);
            c--;
            t2 = aux;
            aux = t1;
            t1 = g[k];
            c++;
            gen(k + 1);
            c--;
            t1 = aux;
        }
    }
}

int main()
{
    int i;
    in >> n >> gmax;
    for (i = 0; i < n; i++) in >> g[i];
    c = 2;
    gen(0);
    cout << mini;
    return 0;
}
