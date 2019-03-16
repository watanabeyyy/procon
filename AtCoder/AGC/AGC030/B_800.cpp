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

ll L, N;
ll X[200001];
ll ans = 0;
ll sumR[200001];
ll sumL[200001];

signed main()
{
    cin >> L >> N;

    REP(i, N)
    cin >> X[i + 1];
    if (N == 1)
    {
        cout << max(L - X[1], X[1]) << endl;
        return 0;
    }

    sumL[0] = 0;
    REP(i, N)
    sumL[i + 1] = X[i + 1] * 2 + sumL[i];

    sumR[0] = 0;
    REP(i, N)
    sumR[i + 1] = (L - X[N - i]) * 2 + sumR[i];

    ll Le, Ri;
    ll tmp = 0;
    ll nl, nr;
    REP(i, N)
    {
        if (i == 0)
            continue;
        Le = i;
        Ri = N - i;
        REP(j, 2)
        { //start
            REP(k, 2)
            { //end
                if (j == 0 and k == 0)
                {
                    nl = min(Le, Ri + 1);
                    nr = nl - 1;
                }
                else if (j == 1 and k == 1)
                {
                    nr = min(Ri, Le + 1);
                    nl = nr - 1;
                }
                else
                {
                    nl = min(Ri, Le);
                    nr = nl;
                }
                tmp = 0;
                tmp = sumL[Le] - sumL[Le - nl];
                tmp = tmp + sumR[Ri] - sumR[Ri - nr];
                if (k == 0)
                    tmp = tmp - X[Le];
                else
                    tmp = tmp - (L - X[N - Ri + 1]);

                chmax(ans, tmp);
            }
        }
    }
    cout << ans << endl;

    system("pause");
}