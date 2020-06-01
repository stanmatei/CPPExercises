#include <iostream>
#include <string.h>
using namespace std;
char sentence[200], word[200];
int main()
{
    int i, j, l;
    cin.getline(word, 200);
    cin.getline(sentence, 200);
    i = 0;
    j = 0;
    l = strlen(word);
    while(word[i] && sentence[j]){
        if(word[i] == sentence[j]){
            i++;
        }
        j++;
    }
    if(i == l) cout << "yes";
    else cout << "no";

    return 0;
}
