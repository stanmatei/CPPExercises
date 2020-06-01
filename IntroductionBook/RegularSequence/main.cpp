#include <iostream>
#include <fstream>
#define MAXLEN 10000
#define InFile "input.txt"
#define OutFile "output.txt"

using namespace std;
typedef int QueueInt[MAXLEN];
typedef char QueueChar[MAXLEN];
ifstream in(InFile);
ofstream out(OutFile);
char p[100];
QueueChar a;
QueueInt b;
int sa = MAXLEN / 2, ea = MAXLEN / 2 - 1;
int sb = MAXLEN / 2, eb = MAXLEN / 2 - 1;
char s[MAXLEN];

int isOpen(char c){
    return c == '(' || c == '[';
}
int appendEnd(char c){
    int ret;
    if(sa <= ea && !isOpen(c) && a[ea] == p[c]){
        ret = b[eb] + 2;
        ea--; eb--;
        b[eb] += ret;
        return ret;
    }
    a[++ea] = c;
    b[++eb] = 0;
    return 0;
}

int appendStart(char c){
    int ret;
    if(sa <= ea && isOpen(c) && a[sa] == p[c]){
        ret = b[sb] + 2;
        sa++; sb++;
        b[sb] += ret;
        return ret;
    }
    a[--sa] = c;
    b[--sb] = 0;
    return 0;
}

int main(void)
{
    char * c, ch;
    int n, di ,i;
    in >> s;
    p['('] = ')';
    p['['] = ']';
    p[')'] = '(';
    p[']'] = '[';
    b[++eb] = 0;
    for(c = s; *c; ++c) appendEnd(*c);
    in >> n;
    for(i = 0; i < n; i++){
        in >> di;
        in >> ch;
        if(di)
            out << appendEnd(ch) << endl;
        else out << appendStart(ch) << endl;
    }
    return 0;
}
