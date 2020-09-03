#include <iostream>
#define MAXS 100
using namespace std;

char c[100], col[5] = {'w', 'r', 'y', 'g', 'b'};
int red, n;

void gen(int k)
{
    if(k == n){
        c[n] = NULL;
        cout << c << endl;
    }
    else{
        if(c[k - 1] != 'w' && c[k - 1] != 'y'){
            c[k] = 'w';
            gen(k + 1);
            c[k] = 'y';
            gen(k + 1);
        }
        if(c[k - 1] != 'r' && red < n / 2){
            c[k] = 'r';
            gen(k + 1);
        }
        //f(c[k - 1] != 'y' && c[k - 1] != 'w'){}
        if(c[k - 1] != 'g' && c[k - 1] != 'b'){
            c[k] = 'g';
            gen(k + 1);
            c[k] = 'b';
            gen(k + 1);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < 5; i++){
        if(col[i] == 'r'){
            if(n > 1){
                c[0] = col[i];
                red++;
                gen(1);
                red--;
            }
        }
        else{
            c[0] = col[i];
            gen(1);
        }
    }

    return 0;
}
