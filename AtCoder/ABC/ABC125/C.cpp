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

int gcd(int a, int b)
{
    int r, tmp;

    /* 自然数 a > b を確認・入替 */
    if (a < b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }

    /* ユークリッドの互除法 */
    r = a % b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

signed main()
{
    int N;
    vi A;
    cin >> N;
    A.resize(N);
    REP(i, N)
    cin >> A[i];
    // sort(ALL(A));
    vi F, B;
    F.resize(N);
    B.resize(N);
    REP(i, N)
    {
        if (i == 0)
        {
            F[i] = A[i];
            B[N - 1 - i] = A[N - 1 - i];
        }
        else
        {
            F[i] = gcd(F[i - 1], A[i]);
            B[N - 1 - i] = gcd(B[N - 1 - i + 1], A[N - 1 - i]);
        }
    }

    int ans = 0;
    int tmp;
    REP(i, N)
    {
        if (i == 0)
            tmp = B[1];
        else if (i == N - 1)
            tmp = F[N - 2];
        else
            tmp = gcd(F[i - 1], B[i + 1]);
        chmax(ans, tmp);
    }

    cout << ans << endl;
    // system("pause");
}