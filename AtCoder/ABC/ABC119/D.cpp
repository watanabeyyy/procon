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

ll query(ll pos, vi &st) //値渡しはTLE
{
    int a, b;
    a = lower_bound(ALL(st), pos) - st.begin();
    b = upper_bound(ALL(st), pos) - st.begin() - 1;
    return min(abs(st[a] - pos), abs(st[b] - pos));
}
int main()
{
    int A, B, Q;
    vi s, t, x;
    cin >> A >> B >> Q;
    s.resize(A + 1);
    t.resize(B + 1);
    x.resize(Q);
    s[0] = -INF;
    t[0] = -INF;
    FOR(i, 1, A + 1)
    cin >> s[i];
    FOR(i, 1, B + 1)
    cin >> t[i];
    FOR(i, 0, Q)
    cin >> x[i];
    s.push_back(INF);
    t.push_back(INF);

    int idx;
    ll ans;
    REP(i, Q)
    {
        ans = INF;
        idx = lower_bound(ALL(s), x[i]) - s.begin();
        chmin(ans, abs(x[i] - s[idx]) + query(s[idx], t));

        idx = upper_bound(ALL(s), x[i]) - s.begin() - 1;
        chmin(ans, abs(x[i] - s[idx]) + query(s[idx], t));

        idx = lower_bound(ALL(t), x[i]) - t.begin();
        chmin(ans, abs(x[i] - t[idx]) + query(t[idx], s));

        idx = upper_bound(ALL(t), x[i]) - t.begin() - 1;
        chmin(ans, abs(x[i] - t[idx]) + query(t[idx], s));

        cout << ans << endl;
    }
    system("pause");
}