#include <iostream>
#include <fstream>
#define MAXS 20
using namespace std;
ifstream in("salesman.in");

int p[MAXS], sol[MAXS], v[MAXS];
float roads[MAXS][MAXS], mini, sum = 0;
int n;

void min_path(int k)
{
    int i, j, d;
    if(k - 1 == n)
    {
        if(roads[1][p[k - 1]])
        {
           if(sum + roads[p[k - 1]][1] < mini){
                for(i = 1; i <= n; i++) sol[i] = p[i];
                mini = sum + roads[p[k - 1]][1];
            }
        }

    }
    else
    {
        for(i = 2; i <= n; i++){
            if(roads[i][p[k - 1]] && !v[i]){
                v[i] = 1;
                sum += roads[i][p[k - 1]];
                p[k] = i;
                if(sum < mini)
                    min_path(k + 1);
                v[i] = 0;
                sum -= roads[i][p[k - 1]];
            }
        }
    }
}

int main()
{
    int i, j, d;
    in >> n;
    while(!in.eof())
    {
        in >> i >> j >> d;
        roads[i][j] = roads[j][i] = d;
        mini += d;
    }
    p[1] = v[1] = 1;
    mini += 1;
    min_path(2);
    for(i = 1; i <= n; i++) cout << sol[i] << " ";
    cout << sol[1];
    cout << endl << mini;
    return 0;
}
