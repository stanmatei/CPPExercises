#include <iostream>
#include <string.h>
#define MAXS 15
using namespace std;

char w[MAXS];
int word[MAXS];
int n, k;
long int ord = 1;
int main()
{
    int i, j, ok = 1;
    cin.getline(w, 15);
    n = strlen(w);
    for (i = 0; i < n && ok; i++){
        switch(w[i]){
        case 'A':
            word[i] = 1;
            break;
        case 'D':
            word[i] = 2;
            break;
        case 'N':
            word[i] = 3;
            break;
        case 'O':
            word[i] = 4;
            break;
        default:
            ok = 0;
        }
    }
    if (!ok) cout << "Word is not in the list!";
    else{
        for (i = 0; i < n; i++){
            ord +=  (word[i] - 1) * (1 << (2 * (n - 1 - i)));
        }
        cout << ord;
    }
    return 0;
}
