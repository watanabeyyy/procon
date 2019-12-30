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
    vi ABC;
    ABC.resize(3);
    cin >> ABC[0] >> ABC[1] >> ABC[2];
    vi A;
    vi B;
    REP(i, 3)
    {
        if (ABC[i] % 2 == 0)
            A.push_back(ABC[i]);
        else
            B.push_back(ABC[i]);
    }
    int ans = 0;
    if (A.size() == 2)
        swap(A, B);
    if (B.size() == 2)
    {
        B[0]++;
        B[1]++;
        ans++;
    }
    vi AB;
    REP(i, A.size())
    AB.push_back(A[i]);
    REP(i, B.size())
    AB.push_back(B[i]);

    sort(ALL(AB));
    ans += (AB[2] - AB[0]) / 2;
    ans += (AB[2] - AB[1]) / 2;
    cout << ans << endl;

    // system("pause");
}