#include <iostream>
#include <fstream>
#define MAXS 10

using namespace std;

ifstream in("competition.in");
ofstream out("competition.out");



int g[10], p, t[10], n, sol[10], mini = 10000, used[6];

int abs(int x){
    if(x < 0) return -x;
    return x;
}

int find_sum(){
    int sum[6] = {0, 0, 0, 0, 0, 0};
    int i, j, s = 0;
    for(i = 0; i < n; i++){
        sum[t[i]] += g[i];
    }
    for(i = 0; i < p - 1; i++){
        for(j = i + 1; j < p; j++){
           s += abs(sum[i] - sum[j]);
        }
    }
    return s;
}

void gen(int k){
    int used[6], ok = 1;
    if (k == n){
        for (int j = 0; j < n; j++){
            used[t[j]] = 1;
        }
        for (int j = 0; j < p; j++) ok *= used[j];
        if (ok){
            int r = find_sum();
            if(r < mini){
                mini = r;
                for(int i = 0; i < n; i++) sol[i] = t[i];
            }
        }
    }
    else{
        int i, j, u;
        for (i =  0; i < p; i++){
            t[k] =  i;
            u = 0;
            for (j = 0; j <= k; j++) used[t[j]] = 1;
            for (j = 0; j < p; j++) u += used[j];
            if (n - k >= p - u) gen(k + 1);
        }
    }
}

int main()
{
    int i;
    in >> n >> p;
    for (i = 0; i < n; i++) in >> g[i];
    gen(0);
    out << mini << endl;
    for (i = 0; i < p; i++){
        for(int j = 0; j < n; j++){
            if(sol[j] == i) out << j + 1<< " ";
        }
        out << endl;
    }


    return 0;
}
