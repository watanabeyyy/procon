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
    cin >> N;
    string tmp;
    int A, B, BA;
    A = 0;
    B = 0;
    BA = 0;
    int ans = 0;
    REP(i, N)
    {
        cin >> tmp;
        if (tmp[0] == 'B' and tmp[tmp.size() - 1] == 'A')
            BA++;
        else if (tmp[0] == 'B')
            B++;
        else if (tmp[tmp.size() - 1] == 'A')
            A++;
        REP(j, tmp.size() - 2)
        {
            if (tmp.substr(j, 2) == "AB")
                ans++;
        }
    }
    if (BA > 0)
    {
        ans += BA - 1;
        if (A > 0)
        {
            A--;
            ans++;
        }
        if (B > 0)
        {
            B--;
            ans++;
        }
    }
    ans += min(A, B);

    cout << ans << endl;
    // system("pause");
}