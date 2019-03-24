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
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    vi lst;
    lst.resize(N);

    lst[0] = 0;
    REP(i, N - 1)
    {
        if (S[i + 1] == 'C' and S[i] == 'A')
        {
            lst[i + 1] = lst[i] + 1;
        }
        else
        {
            lst[i + 1] = lst[i];
        }
    }

    vi ans;
    ans.resize(Q);
    int l, r;
    REP(i, Q)
    {
        cin >> l >> r;
        ans[i] = lst[r - 1] - lst[l - 1];
    }
    REP(i, Q)
    cout << ans[i] << endl;

    // system("pause");
}