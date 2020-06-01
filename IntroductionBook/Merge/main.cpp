#include <iostream>

using namespace std;
int c[100];
int main()
{
    int i, j, k;
    int n = 6, m = 8;
    int a[] = {1, 4, 7, 13, 34, 50};
    int b[] = {2, 9, 10, 17, 18, 21, 35, 332};

    for(i = j = k = 0; i < n && j < m;){
        c[k++] = (a[i] < b[j]) ? a[i++] : b[j++];
    }
    for(; i < n; i++){
        c[k++] = a[i];
    }
    for(; j < m; j++){
        c[k++] = b[j];
    }
    for(i = 0; i < n + m; i++){
            cout<<c[i]<<" ";
    }

    return 0;
}
