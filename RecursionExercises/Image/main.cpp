#include <iostream>
#include <fstream>
#define MAX 250
using namespace std;
ifstream in("input.in");

char img[MAX][MAX];

int equalPixels(int i1, int j1, int i2, int j2, int pixel){
    int i, j;
    for(i = i1; i <= i2; i++){
        for(j = j1; j <= j2; j++){
            if(img[i][j] != pixel) return 0;
        }
    }
    return 1;
}

unsigned long lenCompress(int i1, int j1, int i2, int j2){
    int mi, mj;
    if(equalPixels(i1, j1, i2, j2, img[i1][j1])) return 2;
    else{
        mi = (i1 + i2) / 2;
        mj = (j1 + j2) / 2;
        return 1 + lenCompress(i1, mj + 1, mi, j2) + lenCompress(mi + 1, mj + 1, i2, j2) +
        lenCompress(mi + 1, j1, i2, mj) + lenCompress(i1, j1, mi, mj);

    }

}

int main()
{
    int n, i ,j;
    in >> n;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            in >> img[i][j];
        }
    }
    cout << lenCompress(0, 0, n - 1, n - 1);
    return 0;
}
