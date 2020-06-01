#include <iostream>
#include <fstream>

using namespace std;
ifstream in("first.txt");
ofstream out("second.txt");
typedef int aSet[256];
aSet a, b;

void readSet(aSet x);
void compare(aSet x, aSet y);
int isIncluded(aSet x, aSet y);

int main()
{
    readSet(a);
    readSet(b);
    in.close();
    compare(a, b);
    return 0;
}

void readSet(aSet x){
    char c;
    c = in.get();
    while(c != '\n'){
        x[c] = 1;
        in.get(c);
    }

    x[' '] = x[10] = 0;
}

void compare(aSet x, aSet y){
    if(isIncluded(x, y)) out << "yes";
    else out << "no";
    out.close();
}

int isIncluded(aSet x, aSet y){
    int flag = 1, i;
    for(i = 'a'; i <= 'z'; i++) if(x[i] && !y[i]) flag = 0;
    for(i = 'A'; i <= 'Z'; i++) if(x[i] && !y[i]) flag = 0;
    for(i = '0'; i <= '9'; i++) if(x[i] && !y[i]) flag = 0;
    return flag;

}

