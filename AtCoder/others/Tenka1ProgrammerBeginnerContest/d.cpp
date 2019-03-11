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

int lst[500][500];
signed main()
{
    int N;
    cin >> N;

    ll tmp = -1;
    FOR(i, 1, 500)
    {
        if (i * (i + 1) == 2 * N)
            tmp = i + 1;
    }
    if (tmp == -1)
    {
        cout << "No" << endl;
        return 0;
    }
    N = tmp;
    cout << "Yes" << endl;
    cout << N << endl;
    tmp = 1;
    REP(i, N)
    {
        FOR(j, 1, N - i)
        {
            lst[i][i + j - 1] = tmp;
            lst[i + j][i] = tmp;
            tmp++;
        }
    }
    REP(i, N)
    {
        cout << N - 1;
        REP(j, N - 1)
        {
            cout << " " << lst[i][j];
        }
        cout << endl;
    }
    // system("pause");
}
