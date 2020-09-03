#include <iostream>
#include <fstream>
#define NMAX 10
using namespace std;

ofstream out("series.out");

int sol[NMAX], n ,lg, nSol = 0;

void gen(int k)
{
    if(k == lg - 1)
    {
        if((sol[k - 1] == n - 1) || (sol[k - 1] == n + 1))
        {
            sol[k] = n;
            nSol++;
            for(int i = 0; i < lg; i++) out << sol[i] << " ";
            out << ";";
        }
    }
    else
    {
        sol[k] = sol[k - 1] + 1;
        gen(k + 1);
        if(sol[k - 1] > 1)
        {
            sol[k] = sol[k - 1] - 1;
            gen(k + 1);
        }
    }
}


int main()
{
    cin >> n >> lg;
    sol[0] = n;
    gen(1);
    if(nSol == 0) cout << "nope";
    return 0;
}
