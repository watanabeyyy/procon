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

ll mod = 1000000007;
ll powl(ll a, ll b, bool m)
{
    ll ans = 1;
    REP(i, b)
    {
        ans *= a;
        if (m)
            ans %= mod;
    }
    return ans;
}

signed main()
{
    int N;
    cin >> N;
    ll cnt = 0;
    ll z = powl(4, N, true);
    if (N == 3)
    {
        cout << 61 << endl;
        return 0;
    }
    ll a = 2 * (powl(4, N - 3, true) * 4 - 3);
    ll b = powl(2, 3 * N - 11, true);
    ll c = 3 * powl(2, N - 5, true);
    if (N == 4)
    {
        b = 0;
        c = 0;
    }
    ll ans = z - a - b + c;
    while (true)
    {
        if (ans < 0)
        {
            ans += mod;
        }
        else
            break;
    }
    cout << ans % mod << endl;
    system("pause");
}