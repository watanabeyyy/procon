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

ll query(ll pos, vi &st)
{
    int a, b;
    a = lower_bound(ALL(st), pos) - st.begin();
    b = upper_bound(ALL(st), pos) - st.begin() - 1;
    return min(abs(st[a] - pos), abs(st[b] - pos));
}
ll solve(ll x)
{
    if (x % 2 == 0)
    {
        if (x % 4 == 0)
        {
            return 0 ^ x;
        }
        else
        {
            return 1 ^ x;
        }
    }
    else
    {
        if ((x + 1) % 4 == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}
int main()
{
    ll A, B;
    cin >> A >> B;
    cout << (solve(A - 1) ^ solve(B)) << endl;
    //system("pause");
}
