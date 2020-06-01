#include <iostream>

using namespace std;
int order[50];
float w[50], c[50], x[50];
int main()
{
    int n, i, aux, solved;
    float wMax, wCurr;
    cin >> n;
    cin >> wMax;
    for(i = 0; i < n; i++){
        order[i] = i;
        cin >> c[i];
        cin >> w[i];
    }

    do{
        solved = 1;
        for(i = 0; i < n - 1; i++){
            float ratio1, ratio2;
            ratio1 = c[order[i]] / w[order[i]];
            ratio2 = c[order[i + 1]] / w[order[i + 1]];
            if(ratio1 < ratio2){
                aux = order[i];
                order[i] = order[i + 1];
                order[i + 1] = aux;
                solved = 0;
            }
        }
    }while(!solved);

    for(wCurr = i = 0; i < n && wCurr < wMax; i++){
        wCurr += w[order[i]];
        x[order[i]] = 100;
    }
    if(wCurr > wMax){
        wCurr -= w[order[i-1]];
        x[order[i-1]] = 100 * ((wMax - wCurr) / w[order[i-1]]);
    }
    for(int i = 0; i < n; i++){
        if(x[i])
            cout << i + 1<< " " <<x[i]<< endl;
    }

    return 0;
}
