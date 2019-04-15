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
    int N, C;
    cin >> N >> C;
    vpii xv;
    xv.resize(N);
    int x, v;
    REP(i, N)
    {
        cin >> x >> v;
        xv[i].first = x;
        xv[i].second = v;
    }
    //累積和
    vi migi;
    migi.resize(N);
    migi[0] = xv[0].second;
    REP(i, N - 1)
    migi[i + 1] = migi[i] + xv[i + 1].second;
    REP(i, N)
    migi[i] -= xv[i].first;
    vi hidari;
    hidari.resize(N);
    hidari[0] = xv[N - 1].second;
    REP(i, N - 1)
    hidari[i + 1] = hidari[i] + xv[N - i - 2].second;
    REP(i, N)
    hidari[i] -= C - xv[N - 1 - i].first;

    int tmp;
    //累積和dp
    vi migidp;
    migidp.resize(N);
    tmp = 0;
    REP(i, N)
    {

        chmax(tmp, migi[i]);
        migidp[i] = tmp;
    }
    vi hidaridp;
    hidaridp.resize(N);
    tmp = 0;
    REP(i, N)
    {
        chmax(tmp, hidari[i]);
        hidaridp[i] = tmp;
    }

    int ans = 0;
    REP(i, N)
    {
        //右回りでiへ行ってから、左回り貪欲
        chmax(ans, migi[i]);
        if (i < N - 1)
        {
            tmp = migi[i] - xv[i].first + hidaridp[N - 1 - (i + 1)];
            chmax(ans, tmp);
        }
        //左回りでiへ行ってから、右回り貪欲
        chmax(ans, hidari[N - 1 - i]);
        if (i > 0)
        {
            tmp = hidari[N - 1 - i] - (C - xv[i].first) + migidp[i - 1];
            chmax(ans, tmp);
        }
    }

    cout << ans << endl;
    // system("pause");
}