#include <iostream>

#define MAXSIZE 100

using namespace std;

int a[MAXSIZE];

int main()
{
    int n, i, done = 0;
    cin >> n;
    while(!done){
        for(i = 0; i < n; i++){
            if(a[i]) cout << i + 1<< " ";
        }

        cout << endl;

        for(i = 0; i < n && a[i]; i++) a[i] = 0;
        if(i == n) done = 1;
        else{
            a[i] = 1;
        }
    }
    return 0;
}
