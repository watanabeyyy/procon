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
    int H, W;
    cin >> H >> W;
    bool A[100][100];
    REP(i, H)
    {
        REP(j, W)
        {
            A[i][j] = false;
        }
    }
    char tmp;
    queue<pii> q;
    REP(i, H)
    {
        REP(j, W)
        {
            cin >> tmp;
            if (tmp == '#')
            {
                A[i][j] = true;
                q.push(make_pair(i, j));
            }
        }
    }
    int ans = 0;
    pii tmpp;
    int th, tw;
    int num;
    while (true)
    {
        num = q.size();
        REP(i, num)
        {
            tmpp = q.front();
            q.pop();
            th = tmpp.first;
            tw = tmpp.second;
            if (th - 1 >= 0 and A[th - 1][tw] == false)
            {
                A[th - 1][tw] = true;
                q.push(make_pair(th - 1, tw));
            }
            if (tw - 1 >= 0 and A[th][tw - 1] == false)
            {
                A[th][tw - 1] = true;
                q.push(make_pair(th, tw - 1));
            }
            if (th + 1 < H and A[th + 1][tw] == false)
            {
                A[th + 1][tw] = true;
                q.push(make_pair(th + 1, tw));
            }
            if (tw + 1 < W and A[th][tw + 1] == false)
            {
                A[th][tw + 1] = true;
                q.push(make_pair(th, tw + 1));
            }
        }
        if (q.empty())
            break;
        ans++;
    }

    cout << ans << endl;
    // system("pause");
}
