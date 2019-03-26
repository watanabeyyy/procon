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

int sk(int a, int b)
{
    while (a != 0)
    {
        if (a < b)
            swap(a, b);
        a %= b;
    }
    return b;
}

signed main()
{
    int N, X;
    cin >> N >> X;
    vi a;
    a.resize(N);
    REP(i, N)
    {
        cin >> a[i];
        a[i] = abs(a[i] - X);
    }
    sort(ALL(a));
    int ans = a[0];
    REP(i, N - 1)
    ans = sk(ans, a[i + 1]);
    cout << ans << endl;
}