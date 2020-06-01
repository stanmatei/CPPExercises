#include <iostream>
//Complexity of n
using namespace std;


int main()
{
    int a[] = {1, 10, 3, -5, 4, 2, -100, 30, 15, 25, -10, 40, 1000};
    int i, j, Smax, sum, start, l, n = 13, k,pos ;
    for(Smax = sum = a[0], start = pos = 0, l = i = 1; i < n; i++){
        if(sum < 0){
            start = i;
            sum = a[i]
        }
        else{
            sum += a[i];
            if(Smax < sum){
                pos = start;
                Smax = sum;
                l = i - start + 1;
            }
        }
    }
    for(i = pos; i < pos + l; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
