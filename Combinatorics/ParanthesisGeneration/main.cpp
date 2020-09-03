#include <iostream>
#define MAXS 40
using namespace std;

int n, no, nc;
char s[MAXS];


void gen(int k) {
    if (k == n)
        cout << s << endl;
    else{
        if (no < n / 2){
            s[k] = '(';
            no++;
            gen(k + 1);
            no--;
        }
        if (nc < no){
            s[k] = ')';
            nc++;
            gen(k + 1);
            nc--;
        }
    }
}

int main()
{
    cin >> n;
    gen(0);
    return 0;
}
