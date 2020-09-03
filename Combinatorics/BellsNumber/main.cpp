#include <iostream>

using namespace std;

//Calculating Bell's number for a set of n elements

int n1;

int stirling(int n, int k) {
    if (n == k || k == 1) return 1;
    return stirling(n -1, k - 1) + k * stirling(n - 1, k);
}
int bell(int n) {
    if (n == 0) return 1;
    int sum = 0;
    for (int i = 1; i <= n; i++){
        sum += stirling(n, i);
    }
    return sum;
}


int main()
{
    cin >> n1;
    cout << bell(n1);
    return 0;
}
