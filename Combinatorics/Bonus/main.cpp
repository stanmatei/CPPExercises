#include <iostream>
#include <fstream>
#define MAXS 35
using namespace std;
ifstream in("bonus.in");
ofstream out("bonus.out");


int n, m, x, s[MAXS];
long int ord;

void det_comb();
long det_ord();


int main()
{
    long int m, i, j;
    int type, a;
    in >> n >> m;
    for (i = 0; i < m; i++){
        for (j = 1; j <= n; j++) s[j] = 0;
        in >> type;
        if (type == 1){
            in >> x;
            for (j = 0; j < x; j++) {
                in >> a; s[a] = 1;
            }
            ord = det_ord();
            out << ord << endl;
        }
        else {
            in >> ord;
            det_comb();
            for (j = 1; j <= n; j++){
                if (s[j]) out << j << " ";
            }
            out << endl;
        }
    }
    in.close();
    out.close();
    return 0;
}


long det_ord(){
    int found = 0;
    long ord1 = 0;
    for (int i = 1; i <= n && found < x; i++){
        ord1 += !(s[i]) * (1 << (n - i)) + s[i];
        found += s[i];
    }
    return ord1;
}

void det_comb(){
    int i = 0;
    while (ord)
    {
        i++;
        if (ord <= (1 << (n - i))){
            s[i] = 1; ord--;
        }
        else
            ord -= 1 << (n - i);

    }

}

