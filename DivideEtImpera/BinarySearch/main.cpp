#include <iostream>

using namespace std;

int a[100], n , x;

int binarySearch(int p, int q){
    if(p > q) return -1;
    int m = (p + q) / 2;
    if(x == a[m]) return m;
    if(x > a[m])
        return binarySearch(m + 1, q);
    return binarySearch(p, m - 1);

}

int main()
{
    int i;
    cin >> n;
    cin >> x;
    for(i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << binarySearch(0, n - 1);
    return 0;
}
