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
const long long INF = 1LL << 50;
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

int dp[100];

void query(int from, int to)
{
    if (from < 0 or to > 60 or to < 0 or to > 60)
        return;
    if (!chmin(dp[to], dp[from] + 1))
        return;

    query(to, to - 1);
    query(to, to + 1);
    query(to, to - 5);
    query(to, to + 5);
    query(to, to - 10);
    query(to, to + 10);
}

signed main()
{
    REP(i, 100)
    dp[i] = INF;

    int A, B;
    cin >> A >> B;
    A = A + 20;
    B = B + 20;

    dp[A] = 0;
    query(A, A - 1);
    query(A, A + 1);
    query(A, A - 5);
    query(A, A + 5);
    query(A, A - 10);
    query(A, A + 10);

    cout << dp[B] << endl;
    system("pause");
}