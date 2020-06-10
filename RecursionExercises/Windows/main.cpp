#include <iostream>
#include <fstream>
#define MAXI 100
using namespace std;

ifstream in("win.in");

struct {int i1, j1, i2, j2;} f[MAXI];
int closed[MAXI];
int r, n;

void read(){
    in >> n;
    for(int i = 0; i < n; i++){
        in >> f[i].i1 >> f[i].j1 >> f[i].i2 >> f[i].j2;
    }
    in.close();
}

int covers(int a, int b){
    if(f[b].j2 >= f[a].j1 && f[b].j2 <= f[a].j2 &&
       f[b].i1 >=  f[a].i1 && f[b].i1 <= f[a].i2)
       {
        return 1;
       }
    return 0;
}

void closeIt(int no){
    for(int i = n - 1; i >= no + 1; i--){
        if(!closed[i] && covers(i, no)) closeIt(i);
    }
    closed[no] = 1;
    r++;
}


int main()
{
    read();
    closeIt(0);
    cout << r;
    return 0;
}
