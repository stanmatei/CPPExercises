#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

char e[200], op[] = "1234567890abcdefghijklmoprstuvwxyz";
int lg, i, ND;

int validateExpression();
int validateTerm();
int validateFactor();


int main()
{
    cin.getline(e, 200);
    lg = strlen(e);
    if(validateExpression()) cout << "The expression is correct!";
    return 0;
}

int validateFactor(){
    int r = 1;
    if(e[i] == '('){
        ND++;
        i++;
        r = validateExpression();
        if(!r) return r;
        if(e[i] != ')'){
            cout <<"Error, no bracket at " << i << endl;
            r = 0;
        }
        else{
            i++;
            ND--;
        }
    }
    else{
        if(!strchr(op, tolower(e[i]))){
            cout << "Operand required at " << i << endl;
            r = 0;
        }
        else i++;
    }
    return r;
}

int validateTerm(){
    int r = validateFactor();
    while(r && i < lg && e[i] == '*'){
        i++;
        r = validateFactor();
    }
    return r;
}

int validateExpression(){
    int r = validateTerm();
    while(r && i < lg && e[i] == '+'){
        i++;
        r = validateTerm();
    }
    if(r && i < lg){
        if(e[i] != ')' || e[i] == ')' && !ND) {cout << "Error!"; r = 0;}
    }
    return r;
}

