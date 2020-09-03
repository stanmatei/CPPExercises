#include <iostream>
#include <string.h>
#include <stdlib.h>
#define MAXS 50
using namespace std;

int n, finalElem[MAXS];
char m[MAXS][50];
int a[MAXS];

void fold(int p, int q)
{
    int ls, ld, i;
    char ss[50], sd[50], aux[50];

    if(p == q) finalElem[p] = 1;
    else
    {
        if((q - p + 1) % 2) ls = (p + q) / 2 - 1;
        else ls = (p + q) / 2;

        ld = (p + q) / 2 + 1;
        fold(p, ls);
        itoa(ls, ss, 10);
        itoa(ld, sd, 10);
        for(i = p; i <= ls; i++)
        {
            strcpy(aux, "S");
            strcat(aux, ss);
            strcat(aux, " ");
            strcat(aux, m[i]);
            strcpy(m[i], aux);
        }
        fold(ld, q);
        for(i = ld; i <= q; i++)
        {
            strcpy(aux, "D");
            strcat(aux, sd);
            strcat(aux, " ");
            strcat(aux, m[i]);
            strcpy(m[i], aux);
        }
    }

}

void foldWithSub(int q, int p){
    if(q == p){
        if(a[p] == 0) finalElem[p] = 1;
    }
    else{
        int ls, ld, i, j,temp[MAXS];
        char aux[50], ss[50], sd[50];
        if((q - p + 1 )% 2){
            ls = (p + q) / 2 - 1;
        }
        else ls = (p + q) / 2;
        ld = (p + q) / 2 + 1;

        i = ls;
        j = ld;
        while(i >= p){
            temp[i - p] = a[i];
            a[i] = a[i] * 2 - a[j];
            i--;
            j++;
        }
        foldWithSub(p, ls);
        itoa(ls, ss, 10);
        itoa(ld, sd, 10);
        for(i = p; i <= ls; i++)
        {
            strcpy(aux, "S");
            strcat(aux, ss);
            strcat(aux, " ");
            strcat(aux, m[i]);
            strcpy(m[i], aux);
        }
        for(i = p; i <= ls; i++) a[i] = temp[i - p];
        i = ls; j = ld;
        while(j <= q){
            temp[j - ld] = a[j];
            a[j] = a[j] * 2 - a[i];
            i--;
            j++;
        }
        foldWithSub(ld, q);
        for(i = ld; i <= q; i++)
        {
            strcpy(aux, "D");
            strcat(aux, sd);
            strcat(aux, " ");
            strcat(aux, m[i]);
            strcpy(m[i], aux);
        }
        for(i = ld; i <= q; i++) a[i] = temp[i - ld];
    }
}


int main()
{
    int i;
    cin >> n;
    for(i = 0; i < n; i++) cin >> a[i];
    foldWithSub(0, n- 1);
    //fold(1, n);
    for(int i = 0; i < n; i++)
    {
        if(finalElem[i])
        {
            cout << i << ": "<< m[i] << endl;
        }
    }
    return 0;
}
