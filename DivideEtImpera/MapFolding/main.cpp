#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <map>
#define MAXS 30
using namespace std;


/*
class Rectangle{
public:
    int w, h;
    int elems[MAXS][MAXS];
    Rectangle(int w1, int h1){
        for(int i = 0; i < h1; i++){
            for(int j = 0;j < w1; j++) cin >> elems[i][j];
        }
        h = h1; w = w1;
    }
    Rectangle(int i1, int j1, int i2, int j2, const Rectangle& r){
        int i, j;
        for(i = 0; i <= i2 - i1; i++){
            for(j = 0; j <= j2 - j1; j++) elems[i][j] = r.elems[i + i1][j + j1];
        }
        w = r.w; h = r.h;
    }
    int getArea(){
        return w * h;
    }
    int foldV(){
        return !(h % 2);
    }
    int foldH(){
        return !(w % 2);
    }
    int is_uniform(){
        int flag = 1;
        int x = elems[0][0];
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(elems[i][j] != x) flag = 0;
            }
        }
        return flag;
    }
    friend bool operator < (const Rectangle &, const Rectangle &);
};

bool operator < (const Rectangle & r1, const Rectangle & r2){
    if(r1.getArea() < r2.getArea) return true;
    return false;
}

map<Rectangle, string> folds;

void foldMap(const Rectangle& r, string s){
    if(!r.is_uniform()){
        if(r.foldV){
            Rectangle rl(0, r.w / 2, r.h - 1, r.w - 1, r);
            foldMap(r1);

        }
    }
}
*/

int fmap[MAXS][MAXS];




int main()
{

    return 0;
}
