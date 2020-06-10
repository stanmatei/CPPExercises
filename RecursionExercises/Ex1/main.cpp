#include <iostream>
#include <string.h>
//Read sentence, display in reverse;
using namespace std;
void mirror(){
    char c[101];
    cin >> c;
    cout << c << " ";
    if(c[strlen(c) - 1] != '.') mirror();
    cout << c << " ";
}

int main()
{
    mirror();
    return 0;
}
