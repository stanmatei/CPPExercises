#include <iostream>
#include <fstream>
#include <math.h>
#define MAXS 20
using namespace std;
ifstream in("point.in");


struct point{
    int x, y, c;
}p[MAXS];

int n, s = 1, smin = MAXS;
float d;

float dist(const point & a, const point & b){
    float l = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    return l;
}
/*
void gen(int k)
{
    int i, aux;
    if(s < smin){
        if(k == n + 1){
            if(s < smin) smin = s;
        }
        else{
            for (i = k + 1; i <= n; i++){
                if(dist(p[i], p[k - 1]) <= d){
                    s++;

                    aux = p[i].c;
                    p[i].c = s;
                    gen(k + 1);
                    p[i].c = aux;

                    aux = p[k - 1].c;
                    p[k - 1].c = s;
                    gen(k + 1);
                    p[k - 1].c = aux;

                    s--;
                }
            }
        }
    }
}
*/

void gen2(int k)
{
    int i, is_possible, ok, j;
    if(s < smin){
        if(k == n + 1){
            if(s < smin) smin = s;
        }
        else{
            ok = 0;
            for (i = 1; i <= s && is_possible; i++){
                is_possible = 1;
                for (j = 1; j < k; j++)
                    if(p[j].c == i && dist(p[j], p[k]) <= d) is_possible = 0;
                if(is_possible){
                    p[k].c = i;
                    ok = 1;
                    gen2(k + 1);
                }
            }
            if(!ok){
                s++;
                p[k].c = s;
                gen2(k + 1);
                s--;
            }
        }
    }

}


int main()
{
    int i;
    in >> n >> d;
    for (i = 1; i <= n; i++) {
        in >> p[i].x >> p[i].y;
    }
    p[1].c = 1;
    gen2(2);
    cout << smin;
    return 0;
}
