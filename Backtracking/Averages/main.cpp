#include <iostream>
#include <fstream>
using namespace std;
ifstream in("averages.in");
ofstream out("averages.out");
float avg, curr_avg = 0;
float fMark, sol[12];
int nSol = 0, sum;

float calc_avg(int k)
{
    int i;
    float s, mc, mn;
    if(k > 2)
    {
        s = 0;
        for(i = 1; i <= k; i++) s += sol[i];
        mn = s / k;
        mc = (fMark + 3.0 * mn) / 4.0;
        return mc;
    }
    return 0;
}

void find_marks(int k)
{
    int i;
    if(k < 11)
    {
        for(i = sol[k - 1]; i <= 10; i++)
        {
            sol[k] = i;
            if(calc_avg(k) == avg)
            {
                cout << calc_avg(k) << endl;
                for(i = 1; i <= k; i++) out << sol[i] << " ";
                out << endl;
                nSol++;
            }
            find_marks(k + 1);
            sol[k] = 0;
        }
    }

}


int main()
{
    in >> avg;
    in >> fMark;
    sol[0] = 1;
    find_marks(1);
    if(nSol == 0) out << "NO";
    return 0;
}
