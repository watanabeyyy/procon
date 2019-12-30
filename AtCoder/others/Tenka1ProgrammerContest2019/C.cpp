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
    cin >> N;
    string S;
    cin >> S;
    vi b;
    b.resize(N);

    int num = 0;
    vi c;
    c.resize(N + 1);
    c[0] = 0;
    vi d;
    d.resize(N + 1);
    d[0] = 0;
    REP(i, N)
    {
        if (S[i] == '.')
        {
            b[i] = false;
            c[i + 1] = c[i] + 1;
            d[i + 1] = d[i];
        }
        else
        {
            b[i] = true;
            num++;
            c[i + 1] = c[i];
            d[i + 1] = d[i] + 1;
        }
    }
    int ans = INF;
    int tmp;
    REP(i, N + 1)
    {
        tmp = d[i] + c[N] - c[i];
        chmin(ans, tmp);
    }

    cout << ans << endl;

    // system("pause");
}