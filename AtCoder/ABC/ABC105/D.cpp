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
    cin >> N >> M;
    UM<int, int> um;
    int a = 0;
    int tmp;
    REP(i, N)
    {
        cin >> tmp;
        a += tmp;
        um[a % M]++;
    }
    int ans = 0;
    for (auto i = um.begin(); i != um.end(); ++i)
    {
        tmp = i->second;
        if (i->first == 0)
            ans += tmp;

        if (tmp > 1)
            ans += tmp * (tmp - 1) / 2;
    }
    cout << ans << endl;
    system("pause");
}