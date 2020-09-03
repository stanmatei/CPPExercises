#include <iostream>
#include <string.h>
#include <stdlib.h>
#define Nmax 50
using namespace std;
int n, finalE[Nmax];
char m[Nmax][50];

void fold(int p, int q){
    int pl, pr, i;
    char sl[50], sr[50], aux[50];
    if(p == q) finalE[p] = 1;
    else{
        if((q - p + 1) % 2) pl = (p + q) / 2 - 1;
        else pl = (p + q) / 2;
        pr = (p + q) / 2 + 1;

        itoa(pl, sl, 10);
        itoa(pr, sr, 10);


        for(i = p; i <= pl; i++){
            strcpy(aux, "S");
            strcat(aux, sl);
            strcat(aux, " ");
            strcat(m[i], aux);
            //strcpy(m[i], aux);
        }
        fold(p, pl);

        for(i = pr; i <= q; i++){
            strcpy(aux, "D");
            strcat(aux, sr);
            strcat(aux, " ");
            strcat(m[i], aux);
            //strcpy(m[i], aux);
        }
        fold(pr, q);

    }
}

int main()
{
    cin >> n;
    fold(1, n);
    for(int i = 1; i <= n; i++){
        //if(finalE[i]){
            cout << i << ": "<< m[i] << endl;
        //}
    }
    return 0;
}
