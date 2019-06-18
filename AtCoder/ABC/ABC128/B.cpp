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
    int N;
    pair<pair<string, int>, int> iSP[101];
    cin >> N;
    REP(i, N)
    {
        iSP[i].second = i + 1;
        cin >> iSP[i].first.first >> iSP[i].first.second;
        iSP[i].first.second *= -1;
    }
    sort(iSP, iSP + N);
    REP(i, N)
    cout << iSP[i].second << endl;

    // system("pause");
}