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
const long long INF = 1LL << 58;
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

ll L, N;
ll X[200001];
ll dp[2001][2001][2]; //時計周りに取った個数、半時計周りに取った個数、最後の向き（時計or半時計）
ll ans = 0;

signed main()
{
    REP(i, 2001)
    {
        REP(j, 2001)
        {
            REP(k, 2)
            {
                dp[i][j][k] = 0;
            }
        }
    }
    cin >> L >> N;

    REP(i, N)
    cin >> X[i + 1];
    dp[1][0][0] = X[1];
    dp[0][1][1] = L - X[N];
    FOR(x, 0, N + 1)
    {
        FOR(y, 0, N + 1)
        {
            if (x + y == N)
            {
                chmax(ans, dp[x][y][0]);
                chmax(ans, dp[x][y][1]);
            }
            else if (x + y < N)
            {
                if (x > 0)
                {
                    dp[x + 1][y][0] = max(dp[x + 1][y][0], dp[x][y][0] + X[x + 1] - X[x]);
                    dp[x][y + 1][1] = max(dp[x][y + 1][1], dp[x][y][0] + X[x] + L - X[N - (y)]);
                }
                if (y > 0)
                {
                    dp[x + 1][y][0] = max(dp[x + 1][y][0], dp[x][y][1] + L - X[N - (y - 1)] + X[x + 1]);
                    dp[x][y + 1][1] = max(dp[x][y + 1][1], dp[x][y][1] + X[N - (y - 1)] - X[N - (y)]);
                }
            }
        }
    }
    cout << ans << endl;

    // system("pause");
}