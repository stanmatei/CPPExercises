#include <iostream>

using namespace std;
char c[200];
int main()
{
    int i;
    cin.getline(c, 200, '.');
    i = 0;
    while(c[i]){
        if(c[i] >= 'a' && c[i] <= 'z') c[i] -= ('a' - 'A');
        i++;
    }
    cout << c << endl;
    return 0;
}
