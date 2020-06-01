#include <iostream>
#include <fstream>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

unsigned int primes[30000];
int main()
{
    int d, x, n, m, i, last = 2, ok = 1;
    in >> m;
    in >> n;
    while(in >> x){
        d = 2;
        while(x > 1){
            while(!(x % d)){
                primes[d]++;
                x = x / d;
            }
            d++;
        }
    }

    //for(i = 0; i < 30000 && !(primes[i] % m); i++);

    for(i = 0; i < 30000 && ok; i++){
        if(primes[i] % m) ok = 0;
    }
    if(ok){
        out << 1 << endl;
        for(i = 2; i < 30000; i++){
            if(primes[i] > 0) out << i << " " << primes[i] / m<< endl;
        }
    }
    else{
        out << 0;
    }

    return 0;
}
