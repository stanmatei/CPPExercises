#include <iostream>
#include <fstream>
#define MAXK 200
#define MAXN 1000
using namespace std;
//should be modified to accommodate factorials of very large numbers
ifstream in("hotel.in");
ofstream out("hotel.out");

int x, emp[MAXN], fl[MAXN], sol[MAXK];
long long ct;
int n, k;
int main()
{
    int i, j;
    in >> n >> k;
    for (i = 0; i < n; i++){
        in >> emp[i];
        in >> fl[i];
        if (!sol[fl[i]]){
             x++;
             sol[fl[i]] = x;
        }
    }
    if (x > k) {
        out << 0;
    }
    else{
        ct = 1;
        for (i = k - x + 1; i <= k; i++) ct *= i;
        out << ct << endl;
        for (i = 0; i < n; i++)
            out << emp[i] << " " << sol[fl[i]] << endl;
    }
    return 0;
}
