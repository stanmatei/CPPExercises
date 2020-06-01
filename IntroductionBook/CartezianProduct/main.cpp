#include <iostream>
#define MAXSIZE 100
using namespace std;
int l[MAXSIZE], e[MAXSIZE];
int main()
{
    int n, i, done = 0;
    cin >>n;
    for(i = 0; i < n; i++){ cin >> l[i]; e[i] = 1;}
    while(!done){
        for(i = 0; i < n; i++) cout <<e[i]<<" ";
        cout << endl;
        for(i = n - 1; i >= 0 && e[i] == l[i]; i--) e[i] = 1;
        if(i < 0) done = 1;
        else{
            e[i]++;
        }
    }
    return 0;
}
