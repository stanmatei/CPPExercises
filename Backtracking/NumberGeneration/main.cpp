#include <iostream>

using namespace std;

int n, len, digits[10], sol[10];

void gen(int k)
{
    int i;
    if(k == len)
    {
        for(i = 0; i < len; i++) cout <<sol[i];
        cout << endl;
    }
    else
    {
        for(i = (k == 0); i < 10; i++)
        {
            if(digits[i] && i >= sol[k - !(k == 0)])
            {
                sol[k] = i;
                gen(k + 1);
            }
        }
    }
}


int main()
{
    cin >> n >> len;
    while(n > 0)
    {
        digits[n % 10] = 1;
        n /= 10;
    }
    gen(0);
    return 0;
}
