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
    int N;
    vi A;
    cin >> N;
    A.resize(N);
    REP(i, N)
    cin >> A[i];

    sort(A.begin(), A.end(), greater<int>());

    while (true)
    {
        if (A.size() == 1)
            break;
        REP(i, A.size() - 1)
        A[i] %= A[A.size() - 1];

        sort(A.begin(), A.end(), greater<int>());
        while (true)
        {
            if (A[A.size() - 1] == 0)
                A.pop_back();
            else
                break;
        }
    }
    cout << A[0] << endl;
    system("pause");
}