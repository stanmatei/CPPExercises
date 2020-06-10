#include <iostream>

using namespace std;
int ac(int m, int n)
{
    if(!m) return n + 1;
    if(!n) return ac(m - 1, 1);
    return ac(m - 1, ac(m, n -1));
}
int main()
{
    int a, b;
    cout << "Hello world!" << endl;
    return 0;
}
