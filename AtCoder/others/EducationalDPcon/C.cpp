#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int N;
    cin >> N;
    int a, b, c;
    ll temp_dp[3];
    ll dp[3];
    cin >> a >> b >> c;
    dp[0] = a;
    dp[1] = b;
    dp[2] = c;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            temp_dp[j] = dp[j];
        }
        cin >> a >> b >> c;
        dp[0] = max(temp_dp[1], temp_dp[2]) + a;
        dp[1] = max(temp_dp[0], temp_dp[2]) + b;
        dp[2] = max(temp_dp[0], temp_dp[1]) + c;
    }
    cout << max(max(dp[0], dp[1]), dp[2]);
    // system("pause");
}