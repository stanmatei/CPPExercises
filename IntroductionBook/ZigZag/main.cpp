#include <iostream>
#include <fstream>
using namespace std;
int a[1000], b[1000];
ifstream in("input.txt");
int main()
{
    int n, i, j, done = 0, aux, k;
    in >> n;
    for(i = 0; i < n; i++){
        in >> a[i];
    }

    while(!done){
        done = 1;
        for(i = 0; i < n - 1; i++){
            if(a[i] > a[i + 1]){
                aux = a[i];
                a[i] = a[i + 1];
                a[i + 1] = aux;
                done = 0;
            }
        }
    }
    i = k = 0;
    j = n - 1;
    while(i < j){
        b[k++] = a[i++];
        b[k++] = a[j--];
    }
    for(i = 0; i < n; i++){
        cout << b[i] << " ";
    }

    return 0;
}
