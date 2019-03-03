#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define PQ priority_queue
#define UM unordered_map
#define ALL(a) (a).begin(), (a).end()
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
const ll INF = (1ll << 60);
typedef pair<ll, ll> pii;
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

int A, B, C;
int main()
{
    cin >> A >> B >> C;
    int ans = B / A;
    if (ans >= C)
    {
        ans = C;
    }
    cout << ans << endl;
    system("pause");
}