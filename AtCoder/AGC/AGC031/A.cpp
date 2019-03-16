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

signed main()
{
    ll mod = 1000000007LL;
    ll N;
    cin >> N;
    UM<char, int> lst;
    for (char c = 'a'; c <= 'z'; c++)
        lst[c] = 0;
    char tmp;
    REP(i, N)
    {
        cin >> tmp;
        lst[tmp]++;
    }
    ll ans = 1;
    for (char c = 'a'; c <= 'z'; c++)
    {
        ans = ans * (lst[c] + 1) % mod;
    }

    cout << (ans + mod - 1) % mod << endl;
    system("pause");
}