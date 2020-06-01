#include <iostream>
#define SIZE 20
using namespace std;

typedef long int Factors[SIZE];
typedef int Powers[SIZE];

Factors divA, divB;
Powers ordA, ordB;
int cA, cB;

void factorise(long, int &, Factors, Powers);
long rise(unsigned, unsigned);
long gcd();
int main()
{
    long int a, b;
    cin >> a >> b;
    factorise(a, cA, divA, ordA);
    factorise(b, cB, divB, ordB);
    cout << gcd();
    return 0;
}

void factorise(long x, int & c, Factors fs, Powers ps){
    long d = 2;
    c = 0;
    while(x > 1){
        if(!(x % d)){
            fs[++c] = d;
            while(!(x % d)){
                x /= d;
                ps[c]++;
            }
        }
        d++;
    }

}

long rise(unsigned x, unsigned y){
    if(y == 0) return 1;
    else{
        return x * rise(x, y - 1);
    }
}

long gcd(){
    int pow, i = 1, j = 1;
    long gcd = 1;
    while(i <= cA && j <=cB){
        if(divA[i] == divB[j]){
            pow = (ordA[i] < ordB[i]) ? ordA[i] : ordB[i];
            gcd *= rise(divA[i], pow);
            i++; j++;
        }
        else{
            if(divA[i] < divB[i]) i++;
            else j++;
        }

    }
    return gcd;
}


