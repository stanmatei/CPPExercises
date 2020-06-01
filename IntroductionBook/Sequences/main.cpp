#include <iostream>
#include <fstream>
using namespace std;
ifstream in ("input.txt");
fstream out ("output.txt");
int sol[10001], b[10000], known[10000];
int main()
{
    int n, m, i, j, start, current, w, ok = 1, maxi;

    in >> n >> m;

    for(i = 1; i <= n; i++){
        in >> b[i];
    }

    for(i = 1; i <= m; i++){
        in >> j;
        in >> sol[j];
        known[sol[j]] = 1;
    }
    current = 1;
    while(current <= n && ok){
        start = current;
        while(!b[current] && current <= n) current++;
        if(current > n) ok = 0;
        for(w = start, j = current; j >= start; j--){
            if(!known[j]){
                while(sol[w]) w++;
                sol[w] = j;
            }
        }
        current++;
    }
    if(!ok){
        out << "IMPOSSIBLE!!";
    }
    else{
        maxi = 0;
        for(i = 1; i <= n; i++){
            if(sol[i] > maxi) maxi = sol[i];
            if(b[i] && maxi != i) ok = 0;
            if(!b[i] && maxi == i) ok = 0;
        }
        if(!ok){
            out << "Impossible!!";
        }
        else{
            for(i = 1; i <= n; i++){
                out << sol[i] << " ";
            }
        }
    }



    return 0;
}
