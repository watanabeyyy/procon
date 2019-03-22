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
    int A;
    cin >> A;
    double B = A / 1000.0;
    int vv;
    if (B < 0.1)
        vv = 0;
    else if (B <= 5)
        vv = 10 * B;
    else if (B <= 30)
        vv = B + 50;
    else if (B <= 70)
        vv = (B - 30) / 5.0 + 80;
    else
        vv = 89;

    cout << setw(2) << setfill('0') << vv << endl;
    // system("pause");
}