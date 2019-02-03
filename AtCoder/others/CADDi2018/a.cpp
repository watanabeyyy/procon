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
    int N;
    cin >> N;
    int ans = 0;
    if (N / 1000 == 2)
    {
        ans++;
    }
    N = N % 1000;
    if (N / 100 == 2)
    {
        ans++;
    }
    N = N % 100;
    if (N / 10 == 2)
    {
        ans++;
    }
    N = N % 10;
    if (N / 1 == 2)
    {
        ans++;
    }
    cout << ans;
    return 0;
}
