#include <iostream>

using namespace std;
int v[1001];
int main()
{
    int n , k, s, i, flag = 0, c = 0;
    n = 8;
    k = 5;
    s = 2;
    while(!flag){
        v[s%n]++;
        if(v[s%n] > 1){
            flag = 1;
        }
        else{
            if(s%n != 0) cout << s%n << " ";
            else cout << 8 <<" ";
        }
        s += k;
    }
    v[n] = v[0];
    for(i = 1; i <= n; i++){
        if(v[i] == 0) c++;
    }
    cout<<endl<<c;

    return 0;
}
