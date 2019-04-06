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
    int X, Y, Z, K;
    vi A, B, C;
    cin >> X >> Y >> Z >> K;
    A.resize(X);
    B.resize(Y);
    C.resize(Z);
    REP(i, X)
    cin >> A[i];
    REP(i, Y)
    cin >> B[i];
    REP(i, Z)
    cin >> C[i];

    vi AB;

    REP(i, A.size())
    REP(j, B.size())
    AB.push_back(A[i] + B[j]);

    sort(ALL(AB));

    vi ABC;
    REP(i, C.size())
    REP(j, AB.size())
    {
        if (j == K)
            break;
        ABC.push_back(C[i] + AB[AB.size() - 1 - j]);
    }

    sort(ALL(ABC));
    REP(i, K)
    cout << ABC[ABC.size() - 1 - i] << endl;

    system("pause");
}