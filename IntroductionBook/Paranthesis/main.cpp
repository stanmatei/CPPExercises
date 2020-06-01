#include <iostream>
#include <string.h>
#define MAXSIZE 100
using namespace std;
char q[MAXSIZE];
int main()
{
    int i, l, maxi = 0, btm, top, correct = 1;
    char c;
    btm = 0;
    top = -1;
    cin.get(c);
    while(c != '.'){
        if(c == '('){
            q[(++top) % MAXSIZE] = '(';
        }
        else if(c == ')'){
            if(btm <= top)
                btm++;
            else{
                correct = 0;
            }
        }
        if(top - btm + 1 > maxi) maxi = top - btm + 1;
        cin.get(c);
    }
    if(btm <= top) correct = 0;
    if(correct)    cout << "yes" << " " << maxi;
    else cout << "no" << " " << maxi;


    return 0;
}
