#include <iostream>
#define MAXSIZE 100
using namespace std;
int mp[100];
int main()
{
    int x, y, v;
    v = 0;
    cin >> x;
    mp[v] = x;
    while(v >= 0)
    {

        y = mp[v];
        if(y >= 12)
        {
            if(--v >= 0)
                mp[v] = y - 1;
        }
        else
        {
            mp[++v] = y + 2;
        }

    }
    cout << "f(" << x << ") = "  << y - 1;
    return 0;
}
