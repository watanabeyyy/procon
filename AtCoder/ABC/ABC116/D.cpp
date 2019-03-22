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

bool pairCompare(const pii &A, const pii &B) { return A.second > B.second; }
bool sushiCompare(const vi &A, const vi &B) { return A[0] > B[0]; }

signed main()
{
    int N, K;
    cin >> N >> K;

    int t, d;
    vvi sushi;

    bool used_list[100001];
    REP(i, 100001)
    used_list[i] = false;

    sushi.resize(N + 1);
    REP(i, N + 1)
    {
        sushi[i].push_back(0);
    }
    REP(i, N)
    {
        cin >> t >> d;
        sushi[t].push_back(d);
    }
    REP(i, N + 1)
    sort(sushi[i].begin(), sushi[i].end(), greater<int>());

    sort(sushi.begin(), sushi.end(), sushiCompare);

    vvi tmp_sushi;
    ll ans = 0;
    ll tmp_ans = 0;
    REP(i, N)
    {
        tmp_ans = tmp_ans + sushi[i][0];
        sushi[i].erase(sushi[i].begin());
        tmp_sushi = sushi;
        REP(j, sushi[i].size())
        cout << sushi[i][j] << " ";
        cout << endl;
    }

    // cout << ans + var * var << endl;
    system("pause");
}