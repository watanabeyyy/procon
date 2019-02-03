#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    long long N, P;
    cin >> N >> P;
    long long temp;
    bool flg;
    for (long long i = pow(P, 1 / double(N)) + 1; i > 0; i--)
    {
        temp = P;
        flg = true;
        if (i == 1)
        {
            cout << i;
            break;
        }
        for (long long j = 0; j < N; j++)
        {
            if (temp % i == 0)
            {
                temp = temp / i;
            }
            else
            {
                flg = false;
                break;
            }
        }
        if (flg)
        {
            cout << i;
            break;
        }
    }
    return 0;
}