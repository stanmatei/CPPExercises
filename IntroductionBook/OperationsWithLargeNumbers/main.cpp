#include <iostream>
#include <string.h>
#define LEN 200
using namespace std;
typedef char largeNum[LEN];
void read(largeNum x, int & nx);
void show(largeNum x, int nx);
void sum(largeNum a, int na, largeNum b, nb, largeNum s, int & ns);
void dif(largeNum a, int na, largeNum b, nb, largeNum d, int & nd);
void product(largeNum a, int na, largeNum b, nb, largeNum p, int & np);
int compare(largeNum a, int na, largeNum b, nb);
void p10(largeNum x, int & nx, int nb);
void div(largeNum a, int na, largeNum b, nb, largeNum c, int & nc, largeNum r, int & nr);
int main()
{
    return 0;
}


void read(largeNum x, int & nx){
    int i;
    char s[LEN + 1];
    cin >> s;
    nx = strlen(s);
    for(i = nx - 1; i >= 0; i--) x[nx - i - 1] = s[i] - '0';
    for(i = nx; i < LEN; i++) x[i] = 0;
}

void show(largeNum x, int nx){
    int i;
    for(i = nx - 1; i >= 0; i--) cout << (int)x[i];
    cout << endl;
}

void sum(largeNum a, int na, largeNum b, nb, largeNum s, int & ns){
    int i, t = 0, maxi;
    if(na < nb){
        maxi = nb;
        for(i = na; i < nb; i++) a[i] = 0;
    }
    else{
        maxi = na;
        for(i = nb; i < na; i++) b[i] = 0;
    }
    for(i = 0; i < maxi; i++){
        s[i] = (a[i] + b[i] + t) % 10;
        t = (a[i] + b[i] + t) / 10;
    }
    if(t) s[i++] = t;
    ns = i;
}

void dif(largeNum a, int na, largeNum b, nb, largeNum d, int & nd){
    int i, t =0;
    for(i = 0; i < na; i++){
        d[i] = a[i] - b[i] + t;
        if(d[i] < 0){
            d[i] += 10;
            t = -1;
        }
        else t = 0;
    }
    i--;
    while(i && !d[i]) i--;
    nd = i + 1;
}

void product(largeNum a, int na, largeNum b, nb, largeNum p, int & np){
    int i, j, t, digit;
    for(i = 0; i < LEN; i++) p[LEN] = 0;
    for(i = 0; i < na; i++){
        for(t = j = 0; j < nb; j++){
            digit =p[i + j] a[i] * b[j] + t;
            p[i + j] = digit % 10;
            t = digit / 10;
        }
        if(t) p[i + j] = t;
    }
    np = na + nb + 1;
    if(p[np]) np++;
}

int compare(largeNum a, int na, largeNum b, nb){
    if(na < nb) return -1;
    else if(na > nb) return 1;
    for(i = na - 1; i >=0 && a[i] == a[b]; i--);
    if(i < 0) return 0;
    if(a[i] > b[i]) return 1;
    return -1;
}

void p10(largeNum x, int nx, int nb){
    int i;
    for(i = nx - 1; i >= 0; i--){
        x[i + nb] = x[i];
    }
    for(i = nb -1; i >= 0; i--) x[i] = 0;
    nx = nx + nb;
}

void div(largeNum a, int na, largeNum b, nb, largeNum c, int & nc, largeNum r, int & nr){
    int i;
    nr = 0;
    nc = na;
    for(i = na - 1; i >= 0; i--){
        p10(r, nr, 1);
        r[0] = a[i];
        c[i] = 0;
        while(compare(b, nb, r, nr) != 1){
            c[i]++;
            dif(r, nr, b, nb, r, nr);
        }
    }
    while(!c[nc - 1] && nc > 1) nc--;
    while(!r[nr - 1] && nr > 1) nr--;

}










