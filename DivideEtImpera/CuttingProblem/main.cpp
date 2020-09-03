#include <iostream>
#include <fstream>
#define MAXHOLES 20
//Finds the largest rectangle by area without any holes in it.
using namespace std;
ifstream in("input.txt");
int n;
int x[MAXHOLES], y[MAXHOLES];
int lp, hp, Smax, lMax, hMax, xMax, yMax;

int inside(int i, int xs, int ys, int l, int h){
    if((x[i] > xs) && (x[i] < xs + l) && (y[i] > ys) && (y[i] < ys + h)) return 1;
    return 0;
}

void cut(int xs, int ys, int l, int h){
    int i = 0;
    while((i < n) && !inside(i, xs, ys, l, h)) i++;
    if(i == n){
        if(l * h > Smax){
            Smax = l * h;
            lMax = l; hMax = h; xMax = xs; yMax = ys;
        }
    }
    else{
        cut(xs, ys, l , y[i] - ys);
        cut(xs, y[i], l, ys + l - y[i]);
        cut(xs, ys, x[i] - xs, h);
        cut(x[i], ys, xs + l - x[i], h);
    }
}

int main()
{
    in >> lp >> hp >>n;
    for(int i =0; i < n; i++) in >> x[i] >> y[i];
    in.close();
    cut(0, 0, lp, hp);
    cout << xMax << " " << yMax << " " << lMax << " " << hMax << " " << Smax;
    return 0;
}
