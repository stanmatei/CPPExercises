#include <iostream>
//Greedy algorithm
using namespace std;
int start[100], theEnd[100], order[100];
int main()
{
    int hour, minute, n, i, j, solved;
    cin >> n;
    for(i = 0; i < n; i++){
        order[i] = i;
        cin>> hour;
        cin >> minute;
        start[i] = hour * 60 + minute;
        cin>> hour;
        cin >> minute;
        theEnd[i] = hour * 60 + minute;
    }

    do{
        solved = 1;
        for(i = 0; i < n - 1; i++){
            if(theEnd[order[i]] > theEnd[order[i + 1]]){
                int aux = order[i];
                order[i] = order[i + 1];
                order[i + 1] = aux;
                solved = 0;
            }
        }
    }while(!solved);

    cout << order[0] + 1<< " ";
    int last;
    for(last = 0, i = 1; i < n; i++){
        if(start[order[i]] >= theEnd[order[last]]){
            cout << order[i] + 1<< " ";
            last = i;
        }
    }


    return 0;
}
