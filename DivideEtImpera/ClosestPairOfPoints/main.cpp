#include <iostream>
#include <math.h>
#define infinity 10000
using namespace std;
struct point{int x, y;} pX[100], pY[100], pAll[100], min1, min2, noPoint;
int n;

int dist(int x1, int y1, int x2, int y2){
    return (int)floor(sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}


void doMergeX(int p, int m, int q){
    int i, j, k = 0;
    point b[100];
    i = p;
    j = m + 1;
    while(i <= m && j <= q){
        if(pX[i].x <= pX[j].x){
            b[k++] = pX[i++];
        }
        else{
            b[k++] = pX[j++];
        }
    }
    for(;i <= m; i++){
        b[k++] = pX[i];
    }
    for(;j <= q; j++){
        b[k++] = pX[j];
    }
    for(i = p; i <= q; i++){
        pX[i] = b[i - p];
    }
}

void mSortX(int p, int q){
    if(q > p){
        int m = (p + q) / 2;
        mSortX(p, m);
        mSortX(m + 1, q);
        doMergeX(p, m, q);
    }
}

void doMergeY(int p, int m, int q){
    int i, j, k = 0;
    point b[100];
    i = p;
    j = m + 1;
    while(i <= m && j <= q){
        if(pY[i].y <= pY[j].y){
            b[k++] = pY[i++];
        }
        else{
            b[k++] = pY[j++];
        }
    }
    for(;i <= m; i++){
        b[k++] = pY[i];
    }
    for(;j <= q; j++){
        b[k++] = pY[j];
    }
    for(i = p; i <= q; i++){
        pY[i] = b[i - p];
    }
}

void mSortY(int p, int q){
    if(q > p){
        int m = (p + q) / 2;
        mSortY(p, m);
        mSortY(m + 1, q);
        doMergeY(p, m, q);
    }
}

void closestSplitPair(int p, int q, int d, point & st, point & dr){
    st = noPoint;
    dr = noPoint;
    int m = (p + q) / 2;
    int xm = pX[m].x;
    point sy[100];
    int i, j, best = d, k = 0, l;
    for(i = 0; i < n; i++){
        if(pY[i].x > xm - d && pY[i].x < xm + d){
            sy[k++] = pY[i];
        }
    }
    if(k <= 7){
        for(i = 0; i < k - 1; i++){
            for(j = i + 1; j < k; j++){
                l = dist(sy[i].x, sy[i].y, sy[j].x, sy[j].y);
                if(l < best){
                    st = sy[i];
                    dr = sy[j];
                    best = l;
                }
            }
        }
    }
    else{
        for(i = 0; i < k - 7; i++){
            for(j = 1; j <= 7; j++){
                l = dist(sy[i].x, sy[i].y, sy[i + j].x, sy[i + j].y);
                if(l < best){
                    st = sy[i];
                    dr = sy[j];
                    best = l;
                }
            }
        }
    }
}


void closestPair(int p, int q, point & st, point & dr){
    float l;
    if(q - p + 1 <= 3){
        float mini = infinity;
        for(int i = p; i < q; i++){
            for(int j = p + 1; j <= q; j++){
                l = dist(pX[i].x, pX[i].y, pX[j].x, pX[j].y);
                if(l < mini){
                    st = pX[i];
                    dr = pX[j];
                    mini = l;
                }
            }
        }
    }
    else{
        point st1, st2, dr1, dr2, st3, dr3;
        int m = (p + q) / 2;
        int l1, l2, d, l3;
        closestPair(p, m, st1, st2);
        closestPair(m + 1, q, dr1, dr2);
        l1 = dist(st1.x, st1.y, st2.x, st2.y);
        l2 = dist(dr1.x, dr1.y, dr2.x, dr2.y);
        d = (l1 < l2) ? l1 : l2;
        closestSplitPair(q, p, d, st3, dr3);
        l3 = dist(st3.x, st3.y, dr3.x, dr3.y);
        if(st3.x != 0 - infinity && st3. y != 0 - infinity){
            st = st3;
            dr = dr3;
        }
        else{
            if(l1 < l2){ st = st1; dr = dr1;}
            else{ st = st2; dr = dr2;}
        }
    }
}


int main()
{
    int i, j;
    noPoint.x = 0 - infinity;
    noPoint.y = 0 - infinity;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> pAll[i].x >> pAll[i].y;
        pX[i] = pY[i] = pAll[i];
    }
    mSortX(0, n - 1);
    mSortY(0, n - 1);
    point p1, p2;
    closestPair(0, n - 1, p1, p2);
    cout << p1.x << " " << p1.y << endl << p2.x << " " << p2.y;

    return 0;
}
