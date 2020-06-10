#include <iostream>
#include <string.h>
using namespace std;

int isAnagram(char * x, char * y){
    char * p;
    if(!*x && !*y) return 1;
    p = strchr(y, *x);
    if(!p) return 0;
    *p = NULL;
    strcat(y, p + 1);
    return isAnagram(x + 1, y);
}

int main()
{

    return 0;
}
