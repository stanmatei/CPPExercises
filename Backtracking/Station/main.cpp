#include <iostream>
#include <fstream>
#include <iomanip>
#define NMAX 101
#define MAXS 10000
using namespace std;

ifstream in("station.in");
ofstream out("station.out");



int m[NMAX], c, s, mc[NMAX], v[NMAX], cs;
double ceq = 10000, ma;

double abs_no(double x){
    if(x < 0) return -x;
    return x;
}

double calcMa(){
    double  x = 0;
    int i;
    for(i = 1; i <= c; i++){
        x += abs_no(mc[i] - ma);
    }

    return x;

}

void findMin(int k)
{
    int i, j;
    if(k == c + 1){
        if(cs == s){
            double x = calcMa();
            if(x < ceq) {
                ceq = x;
            }
        }
    }
    else{
        mc[k] = 0;
        findMin(k + 1);
        for(i = 1; i <= s; i++){
            if(!v[i]){
                mc[k] += m[i];
                v[i] = 1;
                cs += 1;
                findMin(k + 1);
                for(j = 1; j <= s; j++){
                    mc[k] += m[j];
                    v[j] = 1;
                    cs += 1;
                    findMin(k + 1);
                    mc[k] -= m[j];
                    v[j] = 0;
                    cs -= 1;

                }
                mc[k] -= m[i];
                v[j] = 0;
                cs -= 1;
            }
        }


    }

}


int main()
{
    in >> c >> s;
    int i;
    mc[0] = 0;
    int sum = 0;
    for(i = 1; i <= s; i++){
        in >> m[i];
        sum += m[i];
    }
    ma = (double) sum / c;
    findMin(1);
    //out.setprecision(3)
    out << ceq;
    return 0;
}
