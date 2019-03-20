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
    int N;
    vi c;
    c.resize(4);
    REP(i, 4)
    c[i] = 0;
    cin >> N;
    char tmp;
    REP(i, N)
    {
        cin >> tmp;
        c[atoi(&tmp) - 1]++;
    }
    // REP(i, 4)
    // cout << c[i] << endl;
    sort(ALL(c));

    cout << c[3] << " " << c[0] << endl;

    // system("pause");
}