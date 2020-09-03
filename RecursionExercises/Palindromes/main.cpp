#include <iostream>
using namespace std;
//Generate all palindromes in base b of length n
int n, b;
char a[41];

void palindrome(int i)
{
    if(i == n / 2){
        if(a[0] != '0'){
            if(n % 2){
                for(char k = '0'; k < b + '0'; k++){
                    cout << a;
                    cout << k;
                    for(int j = n / 2 - 1; j >= 0; j--){
                        cout << a[j];
                    }
                    cout << endl;
                }
            }
            else{
                cout << a;
                for(int j = n / 2 - 1; j >= 0; j--){
                    cout << a[j];
                }
                cout << endl;
            }
        }

    }
    else{
        for(int j = 0; j < b; j++){
            a[i] = j + '0';
            palindrome(i + 1);
        }

    }
}

int main()
{
    cin >> n >> b;
    palindrome(0);
    return 0;
}



