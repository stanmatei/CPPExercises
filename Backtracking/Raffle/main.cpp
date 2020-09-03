#include <iostream>
#include <fstream>
#define MAXS 100
using namespace std;
ifstream in("raffle.in");
struct  object{
    int v, g;
}f[MAXS];
int n, p, s, vf[MAXS], vg[MAXS], smax, m;

void gen(int k)
{
    int i;
    if(k < n){
        if(s >= smax){
            if(s == smax){
                m++;
            }
        }
        else
        {
           for (i = k; i < n; i++){
                if(!vg[i]){
                    vg[f[i].g] = 1;
                    s += f[i].v;
                    gen(k + 1);
                    s -= f[i].v;
                    vg[f[i].g] = 0;
                }
            }
        }
    }

}

int main()
{
    int i;
    in >> n >> smax;
    for (i = 0; i < n; i++) in >> f[i].v;
    in >> p;
    for (i = 0; i < p; i++) in >> f[i].g;
    gen(0);
    cout << m;
    return 0;
}
