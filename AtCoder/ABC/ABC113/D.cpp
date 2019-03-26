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
    {
        return memo[num];
    }
    else
    {
        memo[num] = kazoeage(0, 0, num);
        return memo[num];
    }
}

signed main()
{
    int H, W, K;
    cin >> H >> W >> K;

    REP(i, 10)
    memo[i] = -1;

    int a[10], tmp[10];
    a[1] = 1;
    FOR(i, 2, W + 1)
    a[i] = 0;

    int num;
    FOR(i, 1, H + 1)
    {
        REP(i, 10)
        tmp[i] = 0;

        FOR(j, 1, W + 1)
        {
            //左に行く
            if (j != 1 and j - 1 >= K - (H - i))
            {
                num = a[j];
                if (j - 1 == 1 or j == W)
                {
                    num *= pat((W - 1) - 2);
                }
                else
                {
                    num *= pat(j - 3);
                    num *= pat((W - 1) - (j - 3) - 3);
                }
                tmp[j - 1] += num;
                tmp[j - 1] %= MOD;
            }
            //下に行く
            if (j >= K - (H - i) and j <= K + (H - i))
            {
                num = a[j];
                if (j == W or j == 1)
                {
                    num *= pat((W - 1) - 1);
                }
                else
                {
                    num *= pat(j - 2);
                    num *= pat((W - 1) - (j - 2) - 2);
                }
                tmp[j] += num;
                tmp[j] %= MOD;
            }

            //右に行く
            if (j != W and j + 1 <= K + (H - i))
            {
                num = a[j];
                if (j + 1 == W or j == 1)
                {
                    num *= pat((W - 1) - 2);
                }
                else
                {
                    num *= pat(j - 2);
                    num *= pat((W - 1) - (j - 2) - 3);
                }
                tmp[j + 1] += num;
                tmp[j + 1] %= MOD;
            }
        }
        REP(j, 10)
        a[j] = tmp[j];
    }

    cout << a[K] << endl;

    // system("pause");
}