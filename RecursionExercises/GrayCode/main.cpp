#include <iostream>
#define MAXI 10
#define MAXI2 (1 << MAXI)
using namespace std;
int n, c[MAXI2][MAXI];

void genCode(int x){
    if(x == 1) c[1][0] = 1;
    else{
        genCode(x - 1);
        for(int i = (1 << (x - 1)) - 1; i >= 0; i--){
            for(int j = 0; j < x - 1; j++){
                c[(1 << x) - i - 1][j] = c[i][j];
            }
            c[(1 << x) - i - 1][x - 1] = 1;
        }
    }
}


int main()
{
    cin >> n;
    genCode(n);
    for(int i = 0; i < (1 << n); i++){
        for(int j = 0; j < n; j++){
            cout <<c[i][j];
        }
        cout << endl;
    }

    return 0;
}
