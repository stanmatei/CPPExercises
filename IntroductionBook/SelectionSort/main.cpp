#include <iostream>

using namespace std;
int v[100];
int main()
{
    int n = 10, a[] = {5, 7, 1, 4, 3, 2, 6, 9, 8, 10};
    int dr, i, maxi, posmax;
    for(dr = n - 1; dr > 0; dr--){
        for(maxi = a[0], i = 1, posmax = 0; i <= dr; i++){
            if(a[i] > maxi){
                maxi = a[i];
                posmax = i;
            }
        }
        a[posmax] = a[dr];
        a[dr] = maxi;

    }
    for(int i = 0; i < n; i++){
            cout<<a[i]<<" ";
    }
 return 0;
}
