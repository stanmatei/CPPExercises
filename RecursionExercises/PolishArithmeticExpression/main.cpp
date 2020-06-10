#include <iostream>
#include <string.h>
//Convert arithmetic expression e to Polish arithmetic expression p
using namespace std;

char e[200], p[200];
int i, lg, lgp;

void transformExpression();
void transformTerm();
void transformFactor();


int main()
{
    cin.getline(e, 200);
    lg = strlen(e);
    transformExpression();
    cout << p;
    return 0;
}

void transformFactor(){
    if(e[i] == '('){
        i++;
        transformExpression();
        i++;
    }
    else{
        p[lgp++] = e[i++];
    }
}

void transformTerm(){
    transformFactor();
    while( i < lg && e[i] == '*'){
        i++;
        transformFactor();
        p[lgp++] = '*';
    }

}

void transformExpression(){
    transformTerm();
    while(i < lg && e[i] == '+'){
        i++;
        transformTerm();
        p[lgp++] = '+';
    }
}

