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
    int N, H, W;
    cin >> N >> H >> W;
    int ans = 0;
    int A, B;
    for (int i = 0; i < N; i++)
    {
        cin >> A >> B;
        if (A >= H && B >= W)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}