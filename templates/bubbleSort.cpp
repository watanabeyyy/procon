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
    int N = 5;
    vi A = {5, 3, 2, 4, 1};
    int ans = 0;
    REP(i, N)
    {
        int tmp = N - 1;
        while (i < tmp)
        {
            if (A[tmp - 1] > A[tmp])
            {
                int t = A[tmp];
                A[tmp] = A[tmp - 1];
                A[tmp - 1] = t;
                ans++;
            }
            tmp--;
        }
    }
    REP(j, N)
    {
        cout << A[j] << " ";
    }
    cout << endl;
    cout << ans << endl;

    return 0;
}