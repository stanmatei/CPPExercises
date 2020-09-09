#include <iostream>
#define MAXS 30
using namespace std;

int p[MAXS], used[MAXS];
int n, k, sum;


void gen (int x){
    if (x == n + 1){
        if (sum == k){
            for (int i = 1; i <= n; i++) cout << p[i] << ' ';
            cout << endl;
        }
    }
    else{
        int temp;
        for (int i = 1; i <= n; i++){
            if (!used[i]){
                temp = 0;
                for (int j = i + 1; j <= n ; j++) temp += used[j];
                if (sum + temp<= k){
                    sum += temp;
                    used[i] = 1;
                    p[x] = i;
                    gen(x + 1);
                    used[i] = 0;
                    sum -= temp;
                }

            }
        }
    }

}

int main()
{
    cin >> n >> k;
    gen(1);
    return 0;
}
