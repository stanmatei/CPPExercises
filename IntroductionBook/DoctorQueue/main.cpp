#include <iostream>
#include <fstream>
#define MAXS 100
using namespace std;
int q[MAXS], stQ, enQ = -1, e[MAXS], t[MAXS], wait;
ifstream in("input.txt");
int main()
{
    int n, i, j, avg1, maxi =0, avg2, c = 0;
    avg1 = 0;
    avg2 = 0;
    while(in){
        in >> e[c] >> t[c];
        c++;
    }
    c--;
    in.close();
    n = (17 - 9) * 60;
    j = 0;
    wait = e[0];
    for(i = 0; i <= n; i++){
        if(e[j] == i) {
            q[++enQ] = j;
            avg2 += t[j];
            j++;
        }
        if(wait == i){
            if(stQ <= enQ){
                avg1 += (wait - e[q[stQ]]);
                wait += t[q[stQ++]];
            }
        }
        if((enQ - stQ + 1) > maxi) maxi = enQ - stQ + 1;

    }
    cout << maxi << " " << avg1 / c << " " << avg2 / c;
    return 0;
}
