#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

ifstream f, d;
ofstream ft;
char line[100], linet[100], name[40];
void init();
char * Translate(char *);
void SearchDict(char *, char *);

int main()
{
    init();
    while(!f.eof()){
        f.getline(line, 100);
        ft << Translate(line) << endl;
    }
    f.close();
    ft.close();
    return 0;
}

void init(){
    //cout << "Source File: "; cin.getline(name, 40);
    strcpy(name, "input.txt");
    f.open(name);
    //cout << "Destination File: "; cin.getline(name, 40);
    strcpy(name, "output.txt");
    ft.open(name);
    strcpy(name, "dict.txt");
    //cout << "Dictionary file: "; cin.getline(name, 40);
}

char * Translate(char line[100]){


    char sep[] = ".,:; ";
    char word[20], tWord[20];
    int i, j, k;
    for(i = j = 0; i < strlen(line);){
        while(i < strlen(line) && strchr(sep, line[i])) linet[j++] = line[i++];
        for(k = 0; i < strlen(line) && !strchr(sep, line[i]);) word[k++] = line[i++];
        word[k++] = NULL;
        SearchDict(word, tWord);
        for(k = 0; tWord[k]; linet[j++] = tWord[k++]);
    }
    linet[j++] = NULL;
    return linet;
}

void SearchDict(char * w, char * wt){
    char l[42], *p;
    d.open(name);
    while(!d.eof()){
        d.getline(l, 42);
        p = l;
        cout << strtok(p, "=") << endl;
        if(!strcmp(p, w)){
            strcpy(wt, strtok(NULL, "\n"));
            d.close();
            return;
        }
    }
    strcpy(wt, w);
    d.close();
}

