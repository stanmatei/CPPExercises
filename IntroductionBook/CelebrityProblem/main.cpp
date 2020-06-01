#include <iostream>

using namespace std;
int v[50][50];
int main()
{
    int n, in = 0, out = 0, celebrity, i;
    cin >> n;
    for(i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>v[i][j];
        }
    }
    for(i = 1, celebrity = 0; i < n; i++){
        if(v[celebrity][i]) celebrity = i;
    }
    for(out = in = i = 0; i < n; i++){
        in += v[i][celebrity];
        out += v[celebrity][i];
    }
    if(out == 1 && in == n){
        cout << celebrity;
    }
    return 0;
}
