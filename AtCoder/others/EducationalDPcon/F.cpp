#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dp[3001][3001] = {0};
int main()
{
    string s, t;
    cin >> s >> t;

    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 1; j <= t.length(); j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i - 1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    string ans = "";
    int idx_i = s.length();
    int idx_j = t.length();
    while (true)
    {
        if (dp[idx_i][idx_j] == 0)
        {
            break;
        }

        if (dp[idx_i - 1][idx_j - 1] + 1 == dp[idx_i][idx_j] && s[idx_i - 1] == t[idx_j - 1])
        {
            ans = t[idx_j - 1] + ans;
            idx_i--;
            idx_j--;
        }
        else
        {
            if (dp[idx_i][idx_j - 1] == dp[idx_i][idx_j])
            {
                idx_j--;
            }
            else
            {
                idx_i--;
            }
        }
    }
    cout << ans << endl;

    // system("pause");
}