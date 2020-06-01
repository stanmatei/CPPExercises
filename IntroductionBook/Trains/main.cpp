#include <iostream>
#include <fstream>
#define MAXS 200
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int l1[MAXS], tracks[MAXS][MAXS], l2[MAXS];
int s1, e1 = -1, v = -1, s[MAXS], e[MAXS], possible = 1, found;
int main()
{
    int n, k, i, j;

    for(i = 0; i < MAXS; i++){
        e[i] = -1;
    }

    in >> n >> k;

    for(i = 0; i < n; i++){
        in >> l1[++e1];
    }

    in.close();

    while(s1 <= e1){
        found = 0;
        i = 0;
        while(!found && i < k){
            if(s[i] <= e[i]){
                if(tracks[i][e[i]] == l1[s1] - 1){
                    tracks[i][++e[i]] = l1[s1++];
                    out << "M " << tracks[i][e[i]] << " "<< i << " " << e[i] << endl;
                    found = 1;
                }
            }
            else{
                tracks[i][++e[i]] = l1[s1++];
                out << "M " << tracks[i][e[i]] << " "<< i << " " << e[i] << endl;
                found = 1;
            }
            i++;
        }
        if(!found){
            possible = 0;
            break;
        }

    }

    while(possible && v < n){

        for(i = 0; i < k; i++){
            if(v != -1){
                while(s[i] <= e[i] && (tracks[i][s[i]] == (l2[v] + 1))){
                    out << "O " << tracks[i][s[i]] << " " << i << " " <<s[i] << endl;
                    l2[++v] = tracks[i][s[i]++];
                }
            }
            else{
                if(tracks[i][s[i]] == 1){
                    out << "O " << tracks[i][s[i]] << " " << i << " " <<s[i] << endl;
                    l2[++v] = tracks[i][s[i]++];
                }
            }

        }
    }



    return 0;
}
