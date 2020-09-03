#include <iostream>
#include <fstream>
#define NMAX 20
using namespace std;
int v[NMAX], m[NMAX], n, s, sum = 0, sol[NMAX], nS = 0;
ifstream in("coins.in");
ofstream out("coins.out");


void pay(int k)
{
    if(k == n){
        if(sum == s){
            nS++;
            out << "Solution number: " << nS << endl;
            for(int i = 0; i < n; i++) out << sol[i] << " coins of value " << v[i] <<endl;
            out << endl;
        }
    }
    else{
        int i, j;
        for(j = 0; j <= m[k] && sum + j * v[k] <= s; j++){
            sol[k] = j;
            sum += (j * v[k]);
            pay(k + 1);
            sum -= (j * v[k]);
        }
    }


}

int main()
{
    in >> n;
    in >> s;
    for(int i = 0; i < n; i++)
        in >> m[i] >> v[i];
    in.close();
    pay(0);
    return 0;
}
