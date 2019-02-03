#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long act(int kukki)
{
    if (kukki % 2 != 0)
    {
        kukki = kukki - 1;
    }
    kukki = kukki / 2;
    return kukki;
}

int main()
{
    long long A, B, N;
    cin >> A >> B >> N;
    bool flg = true;
    for (int i = 0; i < N; i++)
    {
        if (flg == true)
        {
            A = act(A);
            B = B + A;
        }
        else
        {
            B = act(B);
            A = A + B;
        }
        flg = !flg;
    }
    cout << A << " " << B;
    return 0;
}