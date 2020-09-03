#include <iostream>
#include <vector>
using namespace std;
int di[] = {-1, 1, 2, 2, 1, -1, -2, -2};
int dj[] = {2, 2, 1, -1, -2, -2, -1, 1};
int t[20][20], n;
struct pos{
    int i, j;
};

vector<pos> p;

void gen(int i, int j){
    cout << "....... " << i << " " << j << endl;
    for (int k = 0; k < n; k++){
            for (int l = 0; l < n; l++) cout << t[k][l] << " ";
            cout << endl;
    }
    cout << endl;
    int ok = 1;
    for (int k = 0; k < n; k++)
        for (int l = 0; l < n; l++) ok *= t[k][l];
    if(ok){
        vector<pos>::iterator it;
        for (it = p.begin(); it !=  p.end(); it++) cout << "(" <<(*it).i << ", " << (*it).j << ")  ";
        cout << endl;

    }
    else{
        int k, i2, j2;
        pos a;
        for (k = 0; k < 8; k++){
            i2 = i + di[k];
            j2 = j + dj[k];
            if (i2 < n && i2 >= 0 && j2 < n && j2 >= 0){
                if (!t[i2][j2]){
                    a.i = i2;
                    a.j = j2;
                    t[i2][j2] = 1;
                    p.push_back(a);
                    gen(i2, j2);
                    p.pop_back();
                    t[i2][j2] = 0;
                }
            }
        }
    }
}


int main()
{
    cin >> n;
    pos a;
    a.i = 0;
    a.j = 0;
    p.push_back(a);
    t[0][0] = 1;
    gen(0, 0);

    return 0;
}
