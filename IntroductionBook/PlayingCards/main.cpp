#include <iostream>
#include <fstream>


using namespace std;
int v[20001];
ifstream in("input.txt");
int main()
{
    int n, i, result = 0, x;
    in >> n;
    for(i = 0; i < n; i++){
        in >> x;
        v[x] = 1;
        if(v[x - 1] == 0){
            result++;
        }
    }
    result --;
    cout << result<< endl;
    return 0;
}
