#include <iostream>
#include <string.h>
using namespace std;
char e[100];
int lg, i;
int eval();
int evalNo();
int evalMolecule();
int main()
{
    cin.getline(e, 100);
    lg = strlen(e);
    cout << evalMolecule();
    return 0;
}

int evalElem(){
    if(e[i] == '('){
        i++;
        return evalMolecule();
    }
    if(e[i] == 'H') {
        i++;
        return 1;
    }
    if(e[i] == 'C') {
        i++;
        return 12;
    }
    i++;
    return 16;
}

int evalNo(){
    int s = 0;
    while(i < lg && e[i] >= '0' && e[i] <= '9'){
        s = s * 10 + e[i] - '0';
        i++;
    }
    return s;
}

int evalMolecule(){
    int s = 0, a, b;
    while(i < lg && e[i] != ')'){
        a = evalElem();
        b = evalNo();
        if(b) s += a * b;
        else s += a;
    }
    i++;
    return s;
}
