#include <iostream>

using namespace std;
int a[100];
int main()
{
    int i, n = 10, a[] = {5, 7, 1, 4, 3, 2, 6, 9, 8, 10};
    int flag = 0, aux;
    do{
        flag = 0;
        for(i = 0; i < n - 1; i++){
            if(a[i] > a[i + 1]){
                aux = a[i];
                a[i] = a[i + 1];
                a[i + 1] = aux;
                flag = 1;
            }
        }
    }while(flag);


    for(int i = 0; i < n; i++){
            cout<<a[i]<<" ";
    }

    return 0;
}
