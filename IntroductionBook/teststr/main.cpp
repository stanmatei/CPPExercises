#include <iostream>
#include <string.h>
using namespace std;
char c[100];
int main()
{
    cin.getline(c, 100);
    c[1] = NULL;
    cout << strlen(c);
    return 0;
}
