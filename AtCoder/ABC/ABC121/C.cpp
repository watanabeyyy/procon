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

signed main()
{
    int N, M;
    cin >> N >> M;
    vpii lst;

    int A, B;
    REP(i, N)
    {
        cin >> A >> B;
        lst.push_back(make_pair(A, B));
    }
    sort(ALL(lst));
    ll ans = 0;
    REP(i, N)
    {
        // cout << lst[i].first << " " << lst[i].second << endl;
        if (M > lst[i].second)
        {
            ans = ans + lst[i].second * lst[i].first;
            M = M - lst[i].second;
        }
        else
        {
            ans = ans + M * lst[i].first;
            M = M - M;
        }
        if (M == 0)
            break;
    }

    cout << ans;
    // system("pause");
}