#include <iostream>
#include <string.h>
#define MAXLONG 10000

using namespace std;

unsigned long appears(unsigned long x, unsigned long y);
void toString(unsigned long x, char * c, int len);

int main()
{
    unsigned long x, sum = 0, a, b;
    char c[100];
    cin >> a >> b >> x;
    for(; a <= b; a++){
        sum += appears(x, a);
    }
    cout << sum;
    return 0;
}


void toString(unsigned long x, char * c, int len){
    int i;
    for(i = 0; i < len; i++){
        c[i] = 0;
    }
    i = 0;
    while(x > 0){
        c[i++] = x % 10 + '0';
        x /= 10;
    }
    c[i] = NULL;
}

unsigned long appears(unsigned long x, unsigned long y){
    char *p, *pSy;
    char Sx[11], Sy[11];
    unsigned long counter = 0;
    toString(x, Sx, 10);
    toString(y, Sy, 10);
    pSy = Sy;
    while((p = strstr(pSy, Sx)) != NULL){
        counter++;
        pSy = p + 1;
    }
    return counter;
}
