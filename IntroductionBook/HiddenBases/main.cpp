#include <iostream>
#define MAXS 100
using namespace std;

int x[MAXS], v[MAXS], sol[MAXS], temp[MAXS];


int getMinBase(int n);
int fromBase(int x, int b);

int main()
{
    int n, i, j, done = 0, mini, maxi, dif;

    cin >> n;
    for(i = 0; i < n; i++){
        cin >> x[i];
        v[i] = getMinBase(x[i]);
    }
    maxi = fromBase(x[0], v[0]);
    mini = fromBase(x[0], v[0]);
    for(j = 0; j < n; j++){
        if(fromBase(x[j], v[j]) > maxi)
            maxi = fromBase(x[j], v[j]);
        if(fromBase(x[j], v[j]) < mini)
            mini = fromBase(x[j], v[j]);
    }
    dif = maxi - mini;
    while(!done){
        maxi = fromBase(x[0], v[0]);
        mini = fromBase(x[0], v[0]);
        for(j = 0; j < n; j++){
            if(fromBase(x[j], v[j]) > maxi)
                maxi = fromBase(x[j], v[j]);
            if(fromBase(x[j], v[j]) < mini)
                mini = fromBase(x[j], v[j]);
        }
        if(maxi - mini < dif){
            dif = maxi - mini;
            for(j = 0; j < n; j++){
                sol[j] = v[j];
            }
        }
        for(i = n - 1; i >= 0 && v[i] == 10; i--) v[i] = getMinBase(x[i]);
        if(i < 0){
            done = 1;
        }
        else{
            v[i]++;
        }
    }
    mini = fromBase(x[0], sol[0]);
    maxi = fromBase(x[0], sol[0]);
    for(i = 0; i < n; i++){
        cout << x[i] << " base " << sol[i] << endl;
        if(fromBase(x[i], sol[i]) < mini) mini = fromBase(x[i], sol[i]);
        if(fromBase(x[i], sol[i]) > maxi) maxi = fromBase(x[i], sol[i]);
    }
    cout << "a = " << mini << endl;
    cout << "b = " << maxi << endl;

    return 0;
}


int getMinBase(int n){
    int maxi = 0;
    while(n > 0){
        if(n % 10 > maxi) maxi = n % 10;
        n /= 10;
    }
    return maxi + 1;
}

int fromBase(int x, int b){
    int sum = 0, p = 1;
    while(x > 0){
        sum += p * (x % 10);
        p *= b;
        x /= 10;
    }
    return sum;
}
