#include <iostream>

using namespace std;

char a[20];
int n;


void genCode(int i){
    if(i == n) cout << a << endl;
    else{
            /*
        a[i] = '.';
        genCode(i + 1);
        a[i] = '_';
        genCode(i + 1);
        */
        for(int j = 0; j < n; j++){
            a[i] = '0' + j;
            genCode(i + 1);
        }
    }
}


int main()
{
    cin >> n;
    genCode(0);
    return 0;
}
