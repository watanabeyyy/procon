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
    int A[5];
    int tmp = 10;
    int ans = 0;
    REP(i, 5)
    {
        cin >> A[i];
        if (A[i] % 10 > 0)
        {
            chmin(tmp, A[i] % 10);
            ans += A[i] - A[i] % 10 + 10;
        }
        else
        {
            ans += A[i];
        }
    }

    if (tmp > 0)
    {
        ans += tmp;
        ans -= 10;
    }
    cout << ans << endl;
    system("pause");
}