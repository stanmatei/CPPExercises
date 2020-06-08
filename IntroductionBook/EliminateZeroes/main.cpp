#include <iostream>
using namespace std;
template <class T>
void eliminateZeroes(T * v, int & n);
int x[100], n;
int main()
{
    int i, n;
    cin >> n;
    for(i = 0; i < n; i++) cin >> x[i];
    eliminateZeroes(x, n);
    for(i = 0; i < n; i++) cout << x[i] << " ";
    return 0;
}
template <class T>
void eliminateZeroes(T * v, int & n){
    int i, j;
    i = 0;
    while(i < n){
        j = 0;
        while(i + j < n && !v[i + j]) j++;
        if(i + j != n){
            for(int k = i; k < i + j; k++) v[k] = v[k + j ];
        }
        if(!j) i++;
        n -= j;
    }
}
