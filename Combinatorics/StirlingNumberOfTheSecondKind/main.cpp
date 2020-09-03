#include <iostream>

using namespace std;

int n1, k1;

int stirling(int n, int k) {
    if (n == k || k == 1) return 1;
    return stirling(n - 1, k - 1) + stirling(n - 1, k) * k;
}

int main()
{
    cin >> n1 >> k1;
    cout << stirling(n1, k1)
    return 0;
}
