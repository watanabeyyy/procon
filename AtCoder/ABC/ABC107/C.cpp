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
const ll INF = 1LL << 55;
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
    int N, K;
    cin >> N >> K;
    vi A, B;
    A.push_back(0);
    B.push_back(0);
    int tmp;

    REP(i, N)
    {
        cin >> tmp;
        if (tmp < 0)
            A.push_back(-1 * tmp);
        else
            B.push_back(tmp);
    }
    sort(ALL(A));
    sort(ALL(B));
    if (A.size() > B.size())
        swap(A, B);

    int ans = INF;
    REP(i, A.size())
    {
        if (i <= K and K - i < B.size())
        {
            chmin(ans, A[i] + 2 * B[K - i]);
            chmin(ans, 2 * A[i] + B[K - i]);
        }
    }
    cout << ans << endl;
    // system("pause");
}
