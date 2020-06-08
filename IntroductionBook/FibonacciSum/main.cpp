#include <iostream>
#include <string.h>
using namespace std;
char n[81];
void read();
int main()
{
    //int a = 3, b =4;
    //a ^= b ^= a ^= b;
    read();
    cout << n;
    return 0;
}

void read(){
    char c[81];
    cin.get(c, 81);
    for(int i = 0; i <= strlen(c); i++){
        n[i] = c[strlen(c) - i];
        cout << n[i];
    }
    n[strlen(c)] = NULL;
}

