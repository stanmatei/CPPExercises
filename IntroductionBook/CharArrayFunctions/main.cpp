#include <iostream>
#define MAXL 101
using namespace std;
char s1[MAXL], s2[MAXL];

void insertArray(char *s1, char *s2, int i);
void removeChars(char *s1, int i, int l);
int main()
{
    int l1,l2, i, j;
    cin.getline(s1, MAXL);
    cin.getline(s2, MAXL);
    cin >> i;
    insertArray(s1, s2, i);
    cout << s1 << endl;
    removeChars(s1, i, 4);
    cout << s1;
    return 0;
}
void insertArray(char *s1, char *s2, int i){
    int j, l1 = 0, l2 = 0;
    while(s1[l1] != NULL) l1++;
    while(s2[l2] != NULL) l2++;
    if(l1 + l2 <= MAXL)
    {
        for(j = i; j < l1; j++) s1[j + l2] =  s1[j];
        for(j = i; j < i + l2; j++) s1[j] = s2[j - i];
    }

}
void removeChars(char *s1, int i, int l){
    int l1 =0, j;
    while(s1[l1] != NULL) l1++;
    for(j = i; j < i + l && s1[j] != NULL; j++){
        s1[j] = s1[j + l];
    }
}
