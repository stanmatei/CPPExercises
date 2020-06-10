#include <iostream>
#include <fstream>
#define MX 100
using namespace std;

ifstream in("f.in");

char nf[MX];
char s[100];
int a[MX];
int noF = 0;

void read();
int ar(char);
void Restore(int &);


int main()
{
    int i = 0;
    read();
    Restore(i);
    return 0;
}

void read(){
    in.getline(s, 100);
    noF = 0;
    char c;
    int k;
    while(!in.eof()){
        in >> c >> k;
        nf[noF] = c;
        a[noF++] = k;

    }
    for(int j = 0; j < noF; j++) cout << nf[j] << " ";
    //noF--;
    cout << endl;
    cout << s << endl;
    in.close();
}

int ar(char c){
    for(int j = 0; j < noF; j++){
        if(nf[j] == c) return a[j];
    }
    return 0;
}

void Restore(int & i){
    int k, j;
    cout << s[i];
    k = ar(s[i++]);
    if(k){
        cout << "(";
        for(j = 1; j < k; j++){
            Restore(i);
            cout << ",";
        }
        Restore(i);
        cout << ")";
    }
}

