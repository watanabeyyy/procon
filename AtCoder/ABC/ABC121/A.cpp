#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
template <class string>
inline bool chmax(string &a, string b)
{
    if (a == "-")
    {
        a = b;
        return true;
    }
    if (a.size() < b.size())
    {
        a = b;
        return true;
    }
    else if (a.size() == b.size() and a < b)
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

int main()
{
    int H, W;
    cin >> H >> W;
    int ans = H * W;
    int h, w;
    cin >> h >> w;
    ans = ans - h * W - w * H + h * w;
    cout << ans << endl;

    // system("pause");
}