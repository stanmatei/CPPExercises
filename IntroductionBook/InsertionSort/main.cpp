#include <iostream>

using namespace std;
int a[100];
int main()
{
    int i, n = 10, a[] = {5, 7, 1, 4, 3, 2, 6, 9, 8, 10};
    int pos, v;
    for(int i = 1; i < n; i++){
        v = a[i];
        for(pos = i; pos && a[pos-1] > v; pos--){
            a[pos] = a[pos - 1];
        }
        a[pos] = v;
    }


    for(int i = 0; i < n; i++){
            cout<<a[i]<<" ";
    }

    return 0;
}
