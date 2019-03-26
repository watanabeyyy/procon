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
    string a, b;
    cin >> a >> b;
    UM<char, int> lsta;
    UM<char, int> lstb;
    int key;
    key = 0;
    REP(i, a.size())
    {
        if (lsta.find(a[i]) == lsta.end())
        {
            lsta[a[i]] = key;
            key++;
        }
        a[i] = lsta[a[i]];
    }
    key = 0;
    REP(i, b.size())
    {
        if (lstb.find(b[i]) == lstb.end())
        {
            lstb[b[i]] = key;
            key++;
        }
        b[i] = lstb[b[i]];
    }
    if (a == b)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
