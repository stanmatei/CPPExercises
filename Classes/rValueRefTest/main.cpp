#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
struct NextNo{
    int a;
    next(){
        a = 0;
    }
    int operator()(){
        return ++a;
    }
};
int main()
{
    vector<bool> v(10, true);
    auto i = 0;
    vector<bool>::iterator it = v.begin();
    auto it2 = v.end();
    NextNo n;
    generate(it, it2, n);
    //v.reserve(50);
    //cout<< v.capacity();
    pair<int, int> p(10,12);
    cout << p.second;
    return 0;
}
