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
    UM<char, int> counter;
    for (char c = 'a'; c <= 'z'; c++)
        counter[c] = 0;
    string S;
    cin >> S;
    REP(i, S.size())
    counter[S[i]]++;

    bool flg = false;
    ll A = 0;
    ll B = 0;
    for (char c = 'a'; c <= 'z'; c++)
    {
        if (counter[c] == 0)
            continue;
        if (counter[c] % 2 != 0)
        {
            counter[c]--;
            if (!flg)
            {
                flg = true;
                A++;
            }
            else
                B++;
            A = A + counter[c];
        }
        else
        {
            A = A + counter[c];
        }
        // cout << A << " " << B << endl;
    }
    cout << A * A + B << endl;

    // system("pause");
}