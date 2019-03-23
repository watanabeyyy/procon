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
    int A = INF;
    int B = INF;
    int tmp;
    cin >> tmp;
    A = min(A, tmp * 4);
    cin >> tmp;
    A = min(A, tmp * 2);
    cin >> tmp;
    A = min(A, tmp * 1);
    cin >> tmp;
    B = min(A * 2, tmp);

    int N;
    cin >> N;
    cout << N % 2 * A + N / 2 * B << endl;
    // system("pause");
}