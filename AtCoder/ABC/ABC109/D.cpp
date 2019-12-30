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
    int H, W;
    cin >> H >> W;

    int a[500][500];
    int b[500][500];
    REP(i, H)
    REP(j, W)
    {
        cin >> a[i][j];
        b[i][j] = a[i][j];
    }
    int ans = 0;
    REP(i, H)
    REP(j, W - 1)
    {
        if (a[i][j] % 2 == 1)
        {
            a[i][j]--;
            a[i][j + 1]++;
            ans++;
        }
    }
    REP(i, H - 1)
    {
        if (a[i][W - 1] % 2 == 1)
        {
            a[i][W - 1]--;
            a[i + 1][W - 1]++;
            ans++;
        }
    }
    cout << ans << endl;

    REP(i, H)
    REP(j, W)
    a[i][j] = b[i][j];

    REP(i, H)
    REP(j, W - 1)
    {
        if (a[i][j] % 2 == 1)
        {
            a[i][j]--;
            a[i][j + 1]++;
            cout << i + 1 << " " << j + 1 << " " << i + 1 << " " << j + 2 << endl;
        }
    }
    REP(i, H - 1)
    {
        if (a[i][W - 1] % 2 == 1)
        {
            a[i][W - 1]--;
            a[i + 1][W - 1]++;
            cout << i + 1 << " " << W << " " << i + 2 << " " << W << endl;
        }
    }
}
