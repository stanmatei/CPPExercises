#include <iostream>
#include <fstream>
#define MAXVAL 8000
using namespace std;
ifstream in("input.txt");
int mins[MAXVAL], maxs[MAXVAL];

int main()
{
    int total = 1, n, i , j, pos, aux, min_c, max_c, max_lwr, min_upr;
    in >> n;
    for(i = 0; i < n; i++){
        in >> mins[i];
        in >> maxs[i];
    }
    //selection sort
    for(i = n - 1; i > 0; i--){
        for(pos = i, j = 0; j < i; j++){
            if(mins[j] > mins[pos] || (mins[j] == mins[pos] && maxs[j] < maxs[pos])) pos = j;
        }
        aux = maxs[i]; maxs[i] = maxs[pos]; maxs[pos] = aux;
        aux = mins[i]; mins[i] = mins[pos]; mins[pos] = aux;
    }
    min_c = mins[0];
    max_c = maxs[0];
    for(i = 1; i < n; i++){
        max_lwr = min_c;
        if(mins[i] > min_c) max_lwr = mins[i];

        min_upr = max_c;

        if(maxs[i] < max_c) min_upr = maxs[i];

        if(max_lwr > min_upr){
            total++;
            min_c = mins[i];
            max_c = maxs[i];
        }
        else{
            min_c = max_lwr;
            max_c = min_upr;
        }
    }
    cout << total;


    return 0;
}
