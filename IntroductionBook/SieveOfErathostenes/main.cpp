#include <iostream>
#define MAXS 1024
using namespace std;
int A[MAXS], primes[MAXS], temp[MAXS];
void intersection(int *a, int *b, int *c);
void reunion(int *a, int *b, int *c);
void difference(int *a, int *b, int *c);
int inclusion(int *a, int *b);
int belongs(int *a, int x);
int main()
{
    int i, d = 2;
    while(d < 1024){
        while(primes[d] && d < 1024) d++;
        for(i = 0; i < 1024; i++) temp[i] = 0;
        for(i = 2; i * d < 1024; i++) temp[i * d] = 1;
        reunion(primes, temp, primes);
        d++;
    }
    for(i = 0; i < 1024; i++) if(!primes[i]) cout << i << " ";
    return 0;
}
void intersection(int *a, int *b, int *c){
    int i;
    for(i = 0; i < MAXS; i++) c[i] = a[i] && b[i];
}

void reunion(int *a, int *b, int *c){
    int i;
    for(i = 0; i < MAXS; i++) c[i] = a[i] || b[i];
}

void difference(int *a, int *b, int *c){
    int i;
    for(i = 0; i < MAXS; i++) c[i] = a[i] && !b[i];
}

int inclusion(int *a, int *b){
    int flag = 0, i;
    for(i = 0; i < MAXS && !flag; i++) if(!a[i] && b[i]) flag = 1;
    return !flag;
}

int belongs(int *a, int x){
    if(a[x]) return 1;
    return 0;
}
