#include <iostream>
//Complexity of n^3
using namespace std;


int main()
{
    int a[] = {1, 10, 3, -5, 4, 2, -100, 30, 15, 25, -10, 40, 1000};
    int i, j, maxSum = a[0], sum, start, l, n = 13, k,pos ;
    for(i = 0; i < n; i++){
        for(j = i; j < n;j++){
            sum = 0;
            for(k = i; k <= j; k++){
                sum += a[k];
            }
            if(sum > maxSum){
                maxSum = sum;
                pos = i;
                l = j - i +1;
            }
        }

    }
    for(i = pos; i < pos + l; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
