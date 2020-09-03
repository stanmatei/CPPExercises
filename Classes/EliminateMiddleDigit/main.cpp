#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class eliminate{
public:
    void operator ()(int & x){
        int i, len = 0;
        vector<int> v;
        while(x) {
            v.push_back(x % 10);
            x /= 10;
        }
        len = v.size();
        for(x = 0, i = len - 1; i > len / 2; i--) x = x * 10 + v[i];
        i -= len % 2 ? 1 : 2;
        while(i >= 0) x = x * 10 + v[i--];
    }
};
int f[1000];
int main()
{
    int n, i;
    cin >> n;
    for(i = 0; i < n; i++) cin >> f[i];
    eliminate e;
    for_each(f, f + n, e);
    for(i = 0; i < n; i++) cout << f[i] << " ";
    return 0;
}
