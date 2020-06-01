#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
ifstream in;
ofstream out;
char c, s1[200], s2[200], buffer[200], ns[100], nd[100];
int lbuffer, ls1, ls2;
void read(){
    cin.getline(ns, 100);
    cin.getline(nd, 100);
    cin.getline(s1, 200);
    cin.getline(s2, 200);
}
void FillBuffer(){
    int i = 1;
    char c[2];
    c[1] = buffer[0] = NULL;
    while((i++ <= lbuffer) && !in.eof()){
        in.get(c[0]);
        strcat(buffer, c);
    }
}

void initialize(){
    in.open(ns);
    out.open(nd);
    lbuffer = ls1 = strlen(s1);
    ls2 = strlen(s2);
    FillBuffer();
}
void left(char * b, char & leftC, int le){
    leftC = b[0];
    for(int i = 0; i < le; i++){
        b[i - 1] = b[i];
    }
}

int main()
{
    read();
    initialize();
    while(!in.eof()){
        if(!strcmp(buffer, s1)){
            out << s2;
            FillBuffer();
        }
        else{
            left(buffer, c, lbuffer);
            out << c;
            cout << c;
            if(!in.eof()){
                in.get(buffer[lbuffer - 1]);
            }
            else{
                strncpy(buffer, buffer, lbuffer - 1);
            }
        }

    }
    out << buffer;
    out.close();
    in.close();
    return 0;
}
