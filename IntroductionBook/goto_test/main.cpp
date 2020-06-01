#include <iostream>

using namespace std;

int main()
{
    int i = 0;
    cond: if(i > 10) goto over;
    cout << i << endl;
    i++;
    goto cond;
    over:cout<<"over";
    return 0;
}
