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

void conb(int a, int b, int &ans)
{
    REP(i, b)
    {
        ans *= a - i;
        while (ans % (i + 1) != 0)
            ans += MOD;
        ans /= i + 1;
        ans %= MOD;
    }
}

signed main()
{
    int N, M;
    cin >> N >> M;

    vi a;

    bool flg = false;
    int tmp = 2;
    while (M > 1)
    {
        if (M % tmp == 0)
        {
            if (!flg)
            {
                a.push_back(1);
                flg = true;
            }
            else
                a[a.size() - 1]++;
            M /= tmp;
        }
        else
        {
            tmp++;
            flg = false;
        }
    }
    int ans = 1;
    REP(i, a.size())
    {
        conb(a[i] + N - 1, a[i], ans);
    }
    cout << ans << endl;

    // system("pause");
}
