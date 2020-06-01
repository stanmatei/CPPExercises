#include <iostream>
#include <fstream>
using namespace std;
int rel[100][100], a[100];
ifstream in("input.txt");
int main()
{
    int n, i, j, sum, pos, aux;
    in >> n;

    for(i = 0; i < n; i++){
        sum = 0;
        for(j = 0; j < n; j++){
            in >> rel[i][j];
            sum += rel[i][j];
        }
        if(sum == 1){
            cout << i << " ";
        }
        a[i] = sum;
    }

    cout << endl;

    for(i = 0; i < n; i++){
        sum = 0;
        for(j = 0; j < n; j++){
            sum += rel[j][i];
        }
        if(sum == 1){
            cout << i << " ";
        }
    }

    cout << endl;

    for(i = 0; i < n; i++){
        for(j = i; j < n; j++){
            if((rel[i][j] == rel[j][i]) * rel[i][j] && i != j) cout << i << " "<< j << endl;
        }
    }
    for(i = n - 1; i > 0; i--){
        for(pos = i, j = i - 1; j >= 0; j--){
            if(a[j] > a[pos]) pos = j;
        }
        aux = a[pos];
        a[pos] = a[i];
        a[i] = aux;
        cout << a[i] << " ";
    }
    cout << a[0] << endl;


    return 0;
}
