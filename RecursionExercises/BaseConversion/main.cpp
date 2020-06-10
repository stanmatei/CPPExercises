#include <iostream>

using namespace std;
void convert(int a, int b){
    if(a){
        convert(a / b, b);
        cout << a % b;
    }

}

int main()
{
    convert(5, 2);
    return 0;
}
