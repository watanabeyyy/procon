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
    int N, M;
    int a, b;
    cin >> N >> M;
    vi ab;
    ab.resize(N + 1);
    REP(i, N + 1)
    ab[i] = INF;
    REP(i, M)
    {
        cin >> a >> b;
        if (ab[a] > b)
            ab[a] = b;
    }
    int ans = 0;
    int tmp = -1;
    REP(i, N + 1)
    {
        if (ab[i] == INF)
            continue;
        if (tmp <= i)
        {
            ans++;
            tmp = ab[i];
        }
        else
        {
            chmin(tmp, ab[i]);
        }
    }
    cout << ans << endl;
    // system("pause");
}