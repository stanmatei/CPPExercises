#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

ifstream in("res.in");

char e[200];
int lg, i;

int getNumber();
int parallel();
int series();


int main()
{
    in.get(e, 200);
    lg = strlen(e);
    cout << series();
    return 0;
}


int getNumber(){
    int r = 0, p = 1;
    if(e[i] == '('){
        i++;
        r =  parallel();
    }
    else{
        i++;
        while(i < lg && e[i] >= '0' && e[i] <= '9'){
            r = r * 10 + e[i] - '0';
            i++;
        }
    }
    return r;
}


int series(){
    int s = 0, k, r;
    s = getNumber();
    while(i < lg && (e[i] == 'R'|| e[i] == '(')){
        s += getNumber();
    }
    return s;
}

int parallel(){
    int p = 1, s = 0, r, k;
    k = series();
    while(i < lg && e[i++] == ','){
        p *= k;
        s += k;
        k = series();
    }
    p *= k;
    s += k;
    r = p / s;
    return r;
}
