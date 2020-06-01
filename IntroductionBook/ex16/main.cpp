#include <iostream>

using namespace std;
int a[10], b[8];
int main()
{
    int i, j, solved = 0, aux, pos, mini, x;
    for(i = 0; i < 10; i++){
        cin >> a[i];
    }
    cin >> mini;
    for(i = 0; i < 7; i++){
        cin >> x;
        if(x < mini) mini = x;
    }

    do{
        solved = 1;
        for(i = 0; i < 9; i++){
            if(a[i] > a[i + 1]){
                aux = a[i];
                a[i] = a[i + 1];
                a[i + 1] = aux;
                solved = 0;
            }
        }
    }while(!solved);
    //4 8 1 9 5 11 3 43 6 20 9 9 6 9 9 8 6 9
    /*
    for(i = 7; i > 0; i--){
        for(pos = i, j = i - 1; j >= 0; j--){
            pos = b[j] > b[pos] ? j : pos;
        }
        aux = b[i];
        b[i] = b[pos];
        b[pos] = aux;
    }
    */

    i = 9;
    while(a[i] >=  mini && i >= 0){
        i--;
    }
    cout << i + 1;

    return 0;
}
