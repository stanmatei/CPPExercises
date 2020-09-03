#include <iostream>

using namespace std;

int digits[10], s, sum;
char c[11];

void gen(int k){
    if(sum >= s){
        if(sum == s){
            c[k] = NULL;
            cout << c << endl;
            if(!digits[0]) cout << c << '0' << endl;
        }
    }
    else
    {
        for (int i = 0; i < 10 && i <= s - sum; i++){
            if(!digits[i]){
                digits[i] = 1;
                sum += i;
                c[k] = i + '0';
                gen(k + 1);
                digits[i] = 0;
                sum -= i;
            }
        }
    }
}

int main()
{
    int i;
    cin >> s;
    for (i = 1; i < 10 && i <= s; i++){
        c[0] = i + '0';
        digits[i] = 1;
        sum += i;
        gen(1);
        digits[i] = 0;
        sum -= i;
    }
    return 0;
}
