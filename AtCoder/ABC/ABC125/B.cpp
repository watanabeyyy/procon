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
    int N;
    vi A, B;
    cin >> N;
    A.resize(N);
    B.resize(N);
    REP(i, N)
    {
        cin >> A[i];
    }
    REP(i, N)
    {
        cin >> B[i];
    }
    int ans = 0;
    int tmp;
    REP(i, N)
    {
        tmp = A[i] - B[i];
        if (tmp > 0)
            ans += tmp;
    }
    cout << ans << endl;
    // system("pause");
}