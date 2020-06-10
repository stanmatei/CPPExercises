#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
ifstream in("input.txt");
struct{char ns; int v;} ts[200];
char e[200];
int lg, i;

int eval(char);
int evaluateFactor();
int evaluateTerm();
int evaluateExpression();

int main()
{
    in.get(e, 200);
    lg =strlen(e);
    int no  = 0;
    while(!in.eof()){
        in >> ts[no].ns >> ts[no].v;
        no++;
    }
    cout << evaluateExpression();
    return 0;
}

int eval(char c){
    int k;
    if(c >= '0' && c <='9') return c - '0';
    else{
        for(k = 0; ts[k].ns != c; k++);
        return ts[k].v;
    }
}

int evaluateFactor(){
    int f;
    if(e[i] != '(') f = eval(e[i++]);
    else{
        i++;
        f = evaluateExpression();
        i++;
    }
    return f;
}

int evaluateTerm(){
    int f = 1;
    f *= evaluateFactor();
    while(i < lg && e[i] == '*'){
        i++;
        f *= evaluateFactor();
    }
    return f;
}

int evaluateExpression(){
    int f = 0;
    f += evaluateTerm();
    while(i < lg && e[i] == '+'){
        i++;
        f += evaluateTerm();
    }
    return f;
}



