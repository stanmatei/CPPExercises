#include <iostream>
#include <iomanip>
#include <fstream>
#define NMAX 101
using namespace std;

ifstream in("stairs.in");
ofstream out("stairs.out");



int n, h, m, p;
int sol[NMAX], minSol[NMAX], v[NMAX], totalH;
double ef[NMAX], minEf;

double effort()
{
    int k, j;
    double x, sum;
    for(k = 1; k <= n; k++){
        x = sol[k] + ef[k - 1];
        sum = sol[k];
        for(j = 2; k - j >= 0; j++)
        {
            sum += sol[k - j + 1];
            if(sum > m) break;
            if(sum / j + p + ef[k - j] < x) x = sum / j + ef[k - j] + p;
        }
        ef[k] = x;
    }
    return ef[n];
}

void gen(int k)
{
    int i;
    if(k == n + 1)
    {
        if(totalH == h)
        {
            double x = effort();
            if(x < minEf){
                minEf = x;
                for(i = 1; i <= n; i++) minSol[i] = sol[i];
            }
        }
    }
    else
    {
        for(i = 1; i <= h && totalH <= h; i++){
            if(!v[i]){
                v[i] = 1;
                sol[k] = i;
                totalH += i;
                gen(k + 1);
                v[i] = 0;
                totalH -= i;
            }
        }
    }

}


int main()
{
    int i;
    in >> h >> n >> m >> p;
    in.close();
    minEf = (double) h * n + 1;
    gen(1);
    out << setprecision(2) << minEf << endl;
    for(i = 1; i <= n; i++) out << minSol[i] << " ";
    out.close();
    return 0;
}
