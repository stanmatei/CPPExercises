#include <iostream>
//calculate En = x1 ** n + x2 ** n

using namespace std;

int s, p;
int r[100];
int recursive(int);
int iterative(int);

int main()
{
    int n;
    cin >> s >> p >> n;
    r[0] = 2;
    r[1] = s;
    cout << recursive(n)<< endl;
    cout << iterative(n);
    return 0;
}


int recursive(int n){
    if(n == 0) return r[0];
    if(n == 1) return r[1];
    return s * recursive(n - 1) - p * recursive(n - 2);
}

int iterative(int n){
    int i, a, b, c;
    a = 2;
    b = s;
    for(i = 0; i < n; i++){
        c = s * b - p * a;
        a = b;
        b = c;
    }
    return a;
}
