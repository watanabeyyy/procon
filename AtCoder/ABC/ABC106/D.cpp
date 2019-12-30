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
    int N, M, Q;
    cin >> N >> M >> Q;
    int A[510][510] = {0};
    int l, r;
    REP(i, M)
    {
        cin >> l >> r;
        A[l][r]++;
    }
    int tmp;
    REP(i, N + 1)
    {
        tmp = 0;
        REP(j, N + 1)
        {
            tmp += A[i][j];
            A[i][j] = tmp;
        }
    }

    vi ans;
    REP(i, Q)
    {
        cin >> l >> r;
        tmp = 0;
        FOR(j, l, r + 1)
        {
            tmp += A[j][r] - A[j][l - 1];
        }
        ans.push_back(tmp);
    }

    REP(i, Q)
    cout << ans[i] << endl;

    // system("pause");
}