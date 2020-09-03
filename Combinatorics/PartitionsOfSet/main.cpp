#include <iostream>

using namespace std;

int n, np, nc, p[30];


void genPartition(int k){
    if (k - 1 == n){
        cout << "Partition " << ++np << ": ";
        for (int j = 1; j <= nc; j++){
            cout << "{ ";
            for (int i = 1; i <= n; i++)
                if (p[i] == j) cout << i << " ";
            cout << "} ";
        }
        cout << endl;
    }
    else {
        for (int j = 1; j <= nc; j++){
            p[k] = j;
            genPartition(k + 1);
        }
        nc++;
        p[k] = nc;
        genPartition(k + 1);
        nc--;
    }
}



int main()
{
    cin >> n;
    genPartition(1);
    return 0;
}
