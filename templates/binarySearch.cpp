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

int binarySearch(vi A, int key)
{
    int left = 0;
    int right = A.size() - 1;

    int idx = (right + left) / 2;
    while (left <= right)
    {
        if (A[idx] == key)
            return 1;
        else if (A[idx] < key)
        {
            left = idx + 1;
            idx = (right + left) / 2;
        }
        else
        {
            right = idx - 1;
            idx = (right + left) / 2;
        }
    }
    return 0;
}

signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    vi S = {1, 2, 3, 4, 5};
    vi T = {3, 4, 1};

    int ans = 0;
    REP(i, T.size())
    {
        vector<int>::iterator pos = lower_bound(S.begin(), S.end(), T[i]);
        int idx = distance(S.begin(), pos);
        if (idx < S.size())
            ans++;
    }
    cout << ans << endl;

    return 0;
}