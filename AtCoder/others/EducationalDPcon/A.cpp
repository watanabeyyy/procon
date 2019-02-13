#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int N;
    int h[100001];
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> h[i];
    }
    ll dp[100001] = {0};
    dp[1] = abs(h[1] - h[0]);
    for (int i = 2; i < N; i++)
    {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << dp[N - 1] << endl;
    // system("pause");
    return 0;
}