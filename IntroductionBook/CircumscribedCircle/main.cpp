#include <iostream>
#include <math.h>
using namespace std;
struct point{
    double x, y;
} A, B, C;
double abs(double x){
    if(x > 0) return x;
    return -x;
}

int main()
{
    double r, area, a, b, c;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;

    a = sqrt((B.x - C.x) * (B.x - C.x) + (B.y - C.y) * (B.y - C.y));
    b = sqrt((A.x - C.x) * (A.x - C.x) + (A.y - C.y) * (A.y - C.y));
    c = sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));

    area = 0.5 * abs(A.x * B.y + B.x * C.y + A.y * C.x - C.x * B.y - C.y * A.x - A.y * B.x);
    r = (a * b * c) / (4 * area) ;
    cout << r;

    return 0;
}
