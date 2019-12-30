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

signed main()
{
    string S;
    cin >> S;
    char A = '0';
    int tmpa = 0;
    char B = '1';
    int tmpb = 0;
    REP(i, S.size())
    {
        if (S[i] == A)
        {
            tmpa++;
        }
        else
        {
            tmpb++;
        }
        if (A == '0')
            A = '1';
        else
            A = '0';
    }
    cout << min(tmpa, tmpb) << endl;
    // system("pause");
}