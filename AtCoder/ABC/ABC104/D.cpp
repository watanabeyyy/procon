#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define UM unordered_map
#define ALL(a) (a).begin(), (a).end()
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef pair<ll, ll> pii;
const ll INF = 1LL << 58;
const ll MOD = 1000000007;
struct Edge
{
    ll s, t, d;
};
typedef vector<vector<Edge>> Graph;
typedef vector<pii> vpii;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

signed main()
{
    string S;
    cin >> S;

    int tmpdp[4] = {0};
    int dp[4] = {0};
    //Aまであってる状態数
    //ABまであってる状態数
    //ABCまであってる状態数
    //今まで一つもとっていない状態数
    dp[3] = 1;
    REP(i, S.size())
    {
        REP(i, 3)
        tmpdp[i] = 0;

        if (S[i] == 'A')
            tmpdp[0] = dp[3];
        else if (S[i] == 'B')
            tmpdp[1] = dp[0];
        else if (S[i] == 'C')
            tmpdp[2] = dp[1];
        else
        {
            tmpdp[0] = dp[0] * 2 + dp[3];
            tmpdp[1] = dp[1] * 2 + dp[0];
            tmpdp[2] = dp[2] * 2 + dp[1];
            dp[3] *= 3;
        }
        REP(i, 4)
        {
            dp[i] += tmpdp[i];
            dp[i] %= MOD;
        }
        // REP(i, 4)
        // cout << dp[i] << " ";
        // cout << endl;
    }
    cout << dp[2] << endl;
    // system("pause");
}