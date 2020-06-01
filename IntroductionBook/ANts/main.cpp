#include <iostream>

using namespace std;
int places[10001], result =200000;
int main()
{
    int n, m, i, maxL, maxR, d , no, l, r, right, left, maxi;
    cin >> d >> no;
    for(i = 1; i <= no; i++) cin >> places[i];
    cin >> n;
    maxL = 0;
    maxR = 0;
    for(i = 0; i < n; i++){
        cin >> l;
        if(l > maxL) maxL = l;
    }
    cin >> m;
    for(i = 0; i < m; i++){
        cin >> r;
        if(r > maxR) maxR = r;
    }
    places[0] = 0;
    places[no + 1] = d;
    for(i = 0; i <= no + 1; i++){
        right = maxR + d - places[i];
        left = maxL + places[i];
        if(left > right) maxi = left;
        else maxi = right;
        if(places[i] > d - places[i]) maxi = maxi + places[i];
        else maxi = maxi + d -places[i];
        if(maxi < result) result = maxi;
    }

    cout << result;
    return 0;
}
