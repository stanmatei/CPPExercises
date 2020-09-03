#include <iostream>
#define MAXS 100
using namespace std;

int e[MAXS], l[MAXS], n;


void gen(int k){
    if (k == n + 1){
        for (int i = 1; i <= n; i++) cout << e[i] << " ";
        cout << endl;
    }
    else{
        int i;
        for (i = 1; i <= l[k]; i++){
            e[k] = i;
            gen(k + 1);
        }
    }
}

int main()
{

    return 0;
}
