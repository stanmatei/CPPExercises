#include <iostream>
#include <fstream>
#define MAXS 100
using namespace std;

ifstream in("rod.in");

int n, m, s, l[MAXS], v[MAXS], smax;

void gen(int k)
{
    if(s >= smax)
        if(s == smax){
            for (int i = 0; i < m; i++) cout << v[i] << " ";
            cout << endl;
        }else;
    else{
        int i;
        for (i = 0; i < m; i++){
            v[i]++;
            s += l[i];
            gen(k + 1);
            s -= l[i];
            v[i]--;
        }
    }
}



int main()
{
    int i;
    in >> n >> m;
    for (i = 0; i < m; i++){
        in >> l[i];
        smax += l[i];
        v[i] = 1;
    }
    smax = n - smax;
    gen(0);
    return 0;
}
