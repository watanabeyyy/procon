#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll;
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

signed main()
{
    ll N;
    cin >> N;
    ll tmp;
    ll lst[200001];
    REP(i, 200001)
    lst[i] = 0;
    ll ans = 0;
    REP(i, N)
    {
        cin >> tmp;
        lst[tmp] = lst[tmp - 1] + 1;
        chmax(ans, lst[tmp]);
    }
    cout << N - ans << endl;
    system("pause");
}
