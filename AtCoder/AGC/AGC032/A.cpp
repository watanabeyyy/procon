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
    int N;
    cin >> N;
    vi b;
    b.resize(N);
    REP(i, N)
    cin >> b[i];

    int tmp;
    vi ans;
    while (true)
    {
        if (ans.size() == N)
            break;
        tmp = -1;
        REP(i, b.size())
        {
            if (b[i] == i + 1)
                tmp = i;
        }
        if (tmp == -1)
            break;

        ans.push_back(b[tmp]);
        b.erase(b.begin() + tmp);
    }
    if (ans.size() == N)
    {
        REP(i, N)
        cout << ans[N - 1 - i] << endl;
    }
    else
        cout << -1 << endl;

    // system("pause");
}
