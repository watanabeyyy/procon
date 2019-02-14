#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int N, K;
    int h[100001];
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> h[i];
    }
    ll dp[100001] = {0};
    dp[1] = abs(h[1] - h[0]);
    ll temp;
    for (int i = 2; i < N; i++)
    {
        temp = dp[i - 1] + abs(h[i] - h[i - 1]);
        for (int j = 0; j < K - 1; j++)
        {
            temp = min(temp, dp[i - j - 2] + abs(h[i] - h[i - j - 2]));
            if ((i - j) == 2)
                break;
        }
        dp[i] = temp;
    }
    cout << dp[N - 1] << endl;
    // system("pause");
    return 0;
}