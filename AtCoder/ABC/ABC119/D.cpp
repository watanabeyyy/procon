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

int main()
{
    int A, B, Q;
    vi s, t, x;
    cin >> A >> B >> Q;
    s.resize(A + 1);
    t.resize(B + 1);
    x.resize(Q + 1);
    s[0] = 0;
    t[0] = 0;
    x[0] = 0;
    REP(i, A)
    cin >> s[i];
    REP(i, B)
    cin >> t[i];
    REP(i, Q)
    cin >> x[i];
    s.push_back(1 << 50);
    t.push_back(1 << 50);
    x.push_back(1 << 50);
    REP(i, Q)
    cout << *lower_bound(ALL(s), x[i]) << endl;
    REP(i, Q)
    cout << *lower_bound(ALL(s), x[i]) << endl;
    system("pause");
}