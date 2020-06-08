#include <iostream>
#define MAXS 1024
using namespace std;
int A[MAXS], B[MAXS], C[MAXS];
void intersection(int *a, int *b, int *c);
void reunion(int *a, int *b, int *c);
void difference(int *a, int *b, int *c);
int inclusion(int *a, int *b);
int belongs(int *a, int x);
int main()
{
    int n, m, i, x;
    cin >> n >> m;
    for(i = 0; i < n; i++) {
        cin >> x;
        A[x] = 1;
    }
    for(i = 0; i < m; i++) {
        cin >> x;
        B[x] = 1;
    }
    intersection(A, B, C);
    for(i = 0; i < MAXS; i++){
        if(C[i]) cout << i << " ";
    }
    cout << endl;

    reunion(A, B, C);
    for(i = 0; i < MAXS; i++){
        if(C[i]) cout << i << " ";
    }
    cout << endl;
    difference(A, B, C);
    for(i = 0; i < MAXS; i++){
        if(C[i]) cout << i << " ";
    }
    cout << endl;

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
