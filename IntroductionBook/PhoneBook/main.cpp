#include <iostream>
#include <string.h>
using namespace std;
char c[21], s[1021];
int main()
{
    int i, l1, j, l2, k;
    cin.getline(c, 21);
    cin.getline(s, 1001);
    l1 = strlen(c);
    l2 = strlen(s);
    i = 0;
    j = 0;
    while(i < l2){
        j = 0;
        while(s[i + j] == c[j] && s[i + j] && c[j]) j++;
        if(j == l1){
            /*for(k = i + l1; k < l2 + l1; k++){
                s[k - l1] = s[k];
            }*/
            strcpy(s + i, s + i + l1);
            l2 -= l1;
        }
        i++;
    }

    cout << s;


    return 0;
}
