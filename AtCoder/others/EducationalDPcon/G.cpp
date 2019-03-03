#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define PQ priority_queue
#define UM unordered_map
#define ALL(a) (a).begin(), (a).end()
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
const ll INF = (1ll << 60);
typedef pair<ll, ll> pii;
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

int N, M;

vi nodes[100001];
int dp[100001];

int dfs(ll idx)
{
    if (dp[idx] != -1)
    {
        return dp[idx];
    }
    else
    {
        int maxima = 0;
        REP(i, nodes[idx].size())
        {
            maxima = max(maxima, dfs(nodes[idx][i]) + 1);
        }
        dp[idx] = maxima;
        return maxima;
    }
}

int main()
{
    cin >> N >> M;
    REP(i, N + 1)
    {
        dp[i] = -1;
    }
    int temp_x, temp_y;
    REP(i, M)
    {
        cin >> temp_x >> temp_y;
        nodes[temp_x].push_back(temp_y);
    }
    int max_L = 0;
    REP(i, N + 1)
    {
        max_L = max(max_L, dfs(i));
    }
    cout << max_L;
    // system("pause");
}