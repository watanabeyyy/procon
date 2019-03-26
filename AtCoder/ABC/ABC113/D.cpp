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

int kazoeage(int now, int sum, int res)
{
    if (res == 0)
        return sum + 1;

    if (now == 1)
        sum = kazoeage(0, sum, res - 1);
    else
    {
        sum = kazoeage(0, sum, res - 1);
        sum = kazoeage(1, sum, res - 1);
    }
    return sum;
}

int memo[10];
int pat(int num)
{
    if (num < 0)
        num = 0;
    if (memo[num] != -1)
        return memo[num];
    else
    {
        memo[num] = kazoeage(0, 0, num);
        return memo[num];
    }
}

int H, W, K;
int ans;

//一層ずつ考えていく
void dfs(int now_h, int now_w, int num)
{
    if (now_h == H + 1)
    {
        ans += num;
        ans %= MOD;
        return;
    }
    //左に行く
    if (now_w != 1 and now_w - 1 >= K - (H - now_h))
    {
        if (now_w - 1 == 1 or now_w == W)
        {
            num *= pat((W - 1) - 2);
        }
        else
        {
            num *= pat(now_w - 3);
            num *= pat((W - 1) - (now_w - 3) - 3);
        }
        dfs(now_h + 1, now_w - 1, num);
    }
    //下に行く
    if (now_w >= K - (H - now_h) and now_w <= K + (H - now_h))
    {
        if (now_w == W or now_w == 1)
        {
            num *= pat((W - 1) - 1);
        }
        else
        {
            num *= pat(now_w - 2);
            num *= pat((W - 1) - (now_w - 2) - 2);
        }
        dfs(now_h + 1, now_w, num);
    }

    //右に行く
    if (now_w != W and now_w + 1 <= K + (H - now_h))
    {
        if (now_w + 1 == W or now_w == 1)
        {
            num *= pat((W - 1) - 2);
        }
        else
        {
            num *= pat(now_w - 2);
            num *= pat((W - 1) - (now_w - 2) - 3);
        }
        dfs(now_h + 1, now_w + 1, num);
    }
}

signed main()
{
    REP(i, 10)
    memo[i] = -1;
    ans = 0;

    cin >> H >> W >> K;
    dfs(1, 1, 1);
    cout << ans << endl;

    system("pause");
}