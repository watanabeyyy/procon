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
    string S;
    cin >> S;
    int ans = 0;
    int cnt = 0;
    int tmp;
    REP(i, S.size())
    {
        tmp = cnt;
        if (S[i] == 'A')
            cnt++;
        if (S[i] == 'T')
            cnt++;
        if (S[i] == 'C')
            cnt++;
        if (S[i] == 'G')
            cnt++;
        if (tmp == cnt or i == S.size() - 1)
        {
            chmax(ans, cnt);
            cnt = 0;
        }
    }
    cout << ans << endl;
    system("pause");
}