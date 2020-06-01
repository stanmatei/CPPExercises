#include <iostream>
//To be continued when I study greedy
using namespace std;
int t[100], p[100], o[100], ot[100], op[100];
int main()
{
    int n, i, j, total, solved, aux;
    cin >> n;
    for(i = 0; i < 2 * n; i++){
        cin >> t[i] >> p[i];
        ot[i] = i;
        op[i] = i;
    }

    solved = 0;
    while(!solved){
        solved = 1;
        for(i = 0; i < n - 1; i++){
            if(t[ot[i]] > t[ot[i + 1]]){
                aux = ot[i];
                ot[i] = ot[i + 1];
                ot[i + 1] = aux;
                solved = 0;
            }
        }
    }
    solved = 0;
    while(!solved){
        solved = 1;
        for(i = 0; i < n - 1; i++){
            if(p[op[i]] < p[op[i + 1]]){
                aux = op[i];
                op[i] = op[i + 1];
                op[i + 1] = aux;
                solved = 0;
            }
        }
    }



    return 0;
}
