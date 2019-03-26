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
UM<int, int> bunkai(int N)
{ //2以上の素因数がkey、その個数がvalue
    UM<int, int> ans;
    int i = 2;
    while (N != 1)
    {
        if (N % i == 0)
        {
            ans[i]++;
            N /= i;
        }
        else
            i++;
    }
    return ans;
}

signed main()
{
    int N;
    cin >> N;

    UM<int, int> soin, temp;
    FOR(i, 2, N + 1)
    {
        temp = bunkai(i);
        for (auto it = temp.begin(); it != temp.end(); ++it)
            soin[it->first] += it->second;
    }
    // for (auto a = soin.begin(); a != soin.end(); ++a)
    // cout << a->first << ":" << a->second << endl;

    int ans = 0;
    for (auto a = soin.begin(); a != soin.end(); ++a)
    {
        if (a->second >= 2)
        {
            for (auto b = soin.begin(); b != soin.end(); ++b)
            {
                if (a != b)
                {
                    if (b->second >= 4)
                        for (auto c = soin.begin(); c != soin.end(); ++c)
                            if (a != c and c->second >= 4 and b->first > c->first)
                                ans++;
                    if (b->second >= 14 and a->second >= 4)
                        ans++;
                    if (b->second >= 24)
                        ans++;
                }
            }
        }
        if (a->second >= 74)
            ans++;
    }
    cout << ans << endl;

    system("pause");
}