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

//binary index tree
//区間の和、要素の値更新がO(log n)
struct BIT
{
    int n;
    vector<int> bi;

    // コンストラクタ
    // 各要素の初期値は 0
    BIT(int num) : bi(num + 1, 0) { n = num; }

    // a_i += w
    void add(int i, int w)
    {
        //補数を使って、最初のビット(LSB)を調べるテク
        for (int x = i; x <= n; x += x & -x)
        {
            bi[x] += w;
        }
    }
    // [1, i] の和を計算.
    int sum(int i)
    {
        int ret = 0;
        for (int x = i; x > 0; x -= x & -x)
        {
            ret += bi[x];
        }
        return ret;
    }
    // [left+1, right] の和を計算.
    int sum(int left, int right)
    {
        return sum(right) - sum(left);
    }
};

signed main()
{
    int n;
    int ans = 0;
    vi a;
    cin >> n;
    a.resize(n);
    REP(i, n)
    cin >> a[i];
    BIT bi(n);

    for (int j = 0; j < n; j++)
    {
        ans += j - bi.sum(a[j]);
        bi.add(a[j], 1);
    }
    cout << ans << endl;
    // system("pause");
}