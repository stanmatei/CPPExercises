#include <iostream>

using namespace std;
int fRec(int);
int fItr(int);
int main()
{
    int n;
    cin >> n;
    cout << fRec(n) << " " << fItr(n);
    return 0;
}


int fRec(int n){
    if(n <= 2) return 1;
    return 3 * fRec(n - 1) - 2 * fRec(n - 3) + fRec(n - 2);
}

int fItr(int n){
    int a, b, c, d;
    a = b = c = 1;
    for(int i = 0; i < n; i++){
        d = 3 * c - 2 * a + b;
        a = b;
        b = c;
        c = d;
    }
    return a;
}
