#include <iostream>
#include <fstream>
#define MAXS 100
using namespace std;

ifstream in("domino.in");

struct domino{
    int first, second;
    void swap_fs(){
        int aux = first;
        first = second;
        second = aux;
    }
}d[MAXS];

int maxLen = 0, n, sol[MAXS], digit[MAXS], res[MAXS], v[MAXS];

void findMax(int k){
    int possible = 0, i;
    for(i = 1; i <= n; i++){
        if(!v[i]){
            if(d[i].second == d[sol[k - 1]].second){
                d[i].swap_fs();
            }
            if(d[i].first == d[sol[k - 1]].second){
                sol[k] = i;
                v[i] = 1;
                findMax(k + 1);
                v[i] = 0;
                possible = 1;
            }

        }

    }
    if(!possible)
    {
        if(k - 1 > maxLen){
            maxLen = k - 1;
            for(i = 1; i < k; i++){
                res[i] = sol[i];
            }
        }
    }
}

int main()
{

    int i;
    in >> n;
    for(i = 1; i <= n; i++) in >> d[i].first >> d[i].second;
    for(i = 1; i <= n; i++)
    {
        sol[1] = i;
        v[i] = 1;
        findMax(2);
        v[i] = 0;

    }
    findMax(0);
    for(i = 1; i <= maxLen; i++) cout << res[i] << " ";
    return 0;
}
