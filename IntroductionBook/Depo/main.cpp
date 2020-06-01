#include <iostream>

using namespace std;
int c[1001], sr[1001];
int main()
{
    int n;
    cin >> n;
    sr[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        sr[i] = sr[i-1] + c[i];
    }
    for(int i = 1; i <=n; i++){
        if(!(sr[i] % n)){
            cout << "The solution is: "<< endl;
            for(int j = 1; j <= i; j++) cout << c[j] <<" ";
            cout << endl;
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            if(!((sr[j]-sr[i])%n)){
                cout << "The solution is: "<< endl;
                for(int k = i + 1; k <= j; k++) cout << c[k] <<" ";
                cout << endl;
            }
        }
    }

    return 0;
}
