#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define UM unordered_map
#define ALL(a) (a).begin(), (a).end()
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef pair<ll, ll> pii;
const long long INF = 1LL << 58;
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

int main()
{
    ll N, M;
    cin >> N >> M;
    ll xyz[1001][3];
    REP(i, N)
    cin >> xyz[i][0] >> xyz[i][1] >> xyz[i][2];
    vi ans;
    vi lis;
    ll tmp;
    REP(i, 1 << 3)
    {
        lis = {};
        REP(j, N)
        {
            tmp = 0;
            REP(k, 3)
            {
                if (i & (1 << k))
                {
                    tmp = tmp + xyz[j][k];
                }
                else
                {
                    tmp = tmp - xyz[j][k];
                }
            }
            lis.push_back(tmp);
        }
        sort(ALL(lis));
        tmp = 0;
        REP(j, M)
        tmp = tmp + lis[lis.size() - 1 - j];
        ans.push_back(tmp);
    }
    sort(ALL(ans));
    cout << ans[ans.size() - 1] << endl;
    //system("pause");
}
