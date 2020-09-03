#include <iostream>

using namespace std;

void moveDiscs(int x, int i, int j){
    if(x > 1){
        moveDiscs(x - 1, i, 6 - i -j);
        cout << i << " -> "<< j << endl;
        moveDiscs(x - 1, 6 - i - j, j);
    }
    else{
        cout << i << " -> " << j << endl;
    }
}


int main()
{
    int n;
    cin >> n;
    moveDiscs(n, 1, 2);
    return 0;
}
