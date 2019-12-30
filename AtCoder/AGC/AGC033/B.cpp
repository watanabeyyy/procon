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
    int H, W, N;
    int r, c;
    string S, T;
    cin >> H >> W >> N;
    cin >> r >> c;
    cin >> S >> T;
    int tr, tc;
    tr = r;
    tc = c;
    r = tr;
    c = tc;
    REP(i, N)
    {
        if (S[i] == 'R')
            c++;
        if (c > W)
        {
            cout << "NO" << endl;
            return 0;
        }
        if (T[i] == 'L')
        {
            c--;
            c = max(1LL, c);
        }
    }
    r = tr;
    c = tc;
    REP(i, N)
    {
        if (S[i] == 'L')
            c--;
        if (c == 0)
        {
            cout << "NO" << endl;
            return 0;
        }
        if (T[i] == 'R')
        {
            c++;
            c = min(W, c);
        }
    }
    r = tr;
    c = tc;
    REP(i, N)
    {
        if (S[i] == 'D')
            r++;
        if (r > H)
        {
            cout << "NO" << endl;
            return 0;
        }
        if (T[i] == 'U')
        {
            r--;
            r = max(1LL, r);
        }
    }
    r = tr;
    c = tc;
    REP(i, N)
    {
        if (S[i] == 'U')
            r--;
        if (r == 0)
        {
            cout << "NO" << endl;
            return 0;
        }
        if (T[i] == 'D')
        {
            r++;
            r = min(H, r);
        }
    }
    cout << "YES" << endl;

    // system("pause");
}
