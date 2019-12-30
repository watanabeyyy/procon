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
    int N;
    cin >> N;
    vi a;
    a.resize(N);
    REP(i, N)
    cin >> a[i];

    int cnt = 0;
    int ans = 0;
    int mi = INF;
    REP(i, N)
    {
        ans += abs(a[i]);
        chmin(mi, abs(a[i]));
        if (a[i] < 0)
            cnt++;
    }

    if (cnt % 2 == 0)
        cout << ans << endl;
    else
        cout << ans - 2 * mi << endl;

    // system("pause");
}