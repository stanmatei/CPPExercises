#include <iostream>
#include <string.h>
#define MAXDIG 1000
using namespace std;
typedef int big[MAXDIG];
char c[MAXDIG + 1];
big m, n, result;

int getLength(big m){
    int last = 0, i = 0;
    while(i < MAXDIG){
        if(m[i] > 0) last = i;
        i++;
    }
    return last + 1;
}

void move10(big x, int p){
    int i;
    for(i = 0; i < p; i++) x[p + i] = x[i];
    for(i = 0; i < p; i++) x[i] = 0;

}

void sum(big a, big b, big s1){
    big s;
    int l = getLength(a), t = 0, i;
    for(i = 0; i < MAXDIG; i++) s[i] = 0;
    for(i = 0; i < l; i++){
        s[i] = (a[i] + b[i] + t) % 10;
        t = (a[i] + b[i] + t) / 10;
    }

    if(t) s[l] = 1;
    for(i = 0; i < l + t; i++){
        s1[i] = s[i];
    }
}

void dif(big a, big b, big d1){
    big d;
    int l = getLength(a), t = 0, i;
    for(i = 0; i < MAXDIG; i++) d[i] = 0;
    for(i = 0; i < l; i++){
        if(a[i] >= b[i] + t){
            d[i] = a[i] - b[i] - t;
            t = 0;
        }
        else{
            d[i] = 10 + a[i] - b[i] - t;
            t = 1;
        }
    }
    for(i = 0; i < l; i++){
        d1[i] = d[i];
    }
}

void mult(big x, big y, big res){
    int l1, l2, maxi, i, j, k;

    l1 = getLength(x);
    l2 = getLength(y);
    for(i = l1 -1; i >= 0; i--) cout << x[i];
    cout << " ";
    for(i = l2 - 1; i >= 0; i--) cout << y[i];
    cout<< endl;
    maxi = (l1 > l2) ? l1 : l2;

    if(maxi <= 1){

        res[0] = (x[0] * y[0]) % 10;
        res[1] = (x[0] * y[0]) / 10;
    }
    else{
        big a, b, c, d, ac, bd, abcd1, abcd2, s1, s2, abcd3;
        for(i = 0; i < l1 / 2; i++){
            b[i] = x[i];
            a[i] = x[l1 / 2 + i];
        }
        if(l1 % 2){
            a[l1 / 2] = x[l1 - 1];
        }

        for(i = 0; i < l2 / 2; i++){
            d[i] = y[i];
            c[i] = y[l2 / 2 + i];
        }
        if(l2 % 2){
            c[l2 / 2] = y[l2 - 1];
        }
        mult(a, c, ac);
        mult(b, d, bd);
        sum(ac, bd, abcd1);
        sum(a, b, s1);
        sum(c, d, s2);
        mult(s1, s2, abcd2);
        dif(abcd2, abcd1, abcd3);
        move10(ac, maxi);
        move10(abcd3, maxi / 2 + maxi % 2);
        sum(ac, abcd3, abcd1);
        sum(abcd1, bd, res);
        k = getLength(res);
    }


}

int main()
{
    int l, i, j;
    cin.getline(c, 1001);
    l = strlen(c);
    for(i = 0; i < l; i++){
        n[l - i - 1] = c[i] - '0';
    }
    cin.getline(c, 1001);
    for(i = 0; i < l; i++){
        m[l - i - 1] = c[i] - '0';
    }
    mult(n, m, result);
    l = getLength(result);
    for(i = 0; i < l; i++) cout << result[l - i - 1];
    return 0;
}


