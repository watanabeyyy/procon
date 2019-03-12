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
    string S;
    cin >> S;
    bool flg;
    for (char c = 'a'; c <= 'z'; c++)
    {
        flg = false;
        REP(i, S.size())
        {
            flg |= (c == S[i]);
        }
        if (!flg)
        {
            cout << S + c << endl;
            return 0;
        }
    }
    string ans = S;
    if (!next_permutation(ALL(ans)))
    {
        cout << -1 << endl;
        return 0;
    }
    REP(i, S.size())
    {
        cout << ans[i];
        if (S[i] != ans[i])
        {
            cout << endl;
            return 0;
        }
    }
}
