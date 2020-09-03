#include <iostream>
#include <fstream>
#define MAXS 100
using namespace std;
ifstream in("exam.in");
ofstream out("exam.out");



int dif[MAXS], sc[MAXS], n, p, d, t, sol, v[MAXS];

void gen(int k)
{
    if(t > p){
        sol++;
        for (int i = 0; i < n; i++){
            if(v[i]) out << i << " ";
        }
        out << endl;
    }
    if(k < n){
        gen(k + 1);
        if(dif[k] <= d){
            t += sc[k];
            v[k] = 1;
            gen(k + 1);
            t -= sc[k];
            v[k] = 0;
        }
    }
}

int main()
{
    int i;
    in >> n >> p >> d;
    for (i = 0; i < n; i++) in >> dif[i];
    for (i = 0; i < n; i++) in >> sc[i];
    gen(0);
    if(!sol) out << "STUDY MORE!";
    return 0;
}
