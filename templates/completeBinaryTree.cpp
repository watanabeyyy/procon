#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
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
    //  以降 cin の入力元が 'input.txt' になる
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    vi v = {7, 8, 1, 2, 3};
    int p, l, r;
    REP(i, v.size())
    {
        cout << "node " << i + 1 << ": key = " << v[i] << ",";
        p = (i + 1) / 2;
        if (p > 0)
        {
            cout << " parent key = " << v[p - 1] << ",";
        }
        l = 2 * (i + 1);
        r = 2 * (i + 1) + 1;
        if (l <= v.size())
        {
            cout << " left key = " << v[l - 1] << ",";
        }
        if (r <= v.size())
        {
            cout << " right key = " << v[r - 1] << ",";
        }
        cout << endl;
    }

    return 0;
}