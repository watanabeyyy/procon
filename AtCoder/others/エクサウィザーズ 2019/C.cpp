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
    int N, Q;
    cin >> N >> Q;

    string s;
    cin >> s;

    vector<pair<char, char>> td;
    td.resize(Q);
    REP(i, Q)
    cin >> td[i].first >> td[i].second;

    int A[2];
    A[0] = 0;
    A[1] = N - 1;

    int tmp;
    int now;
    while (A[1] - A[0] > 1)
    {
        tmp = (A[0] + A[1]) / 2;
        now = tmp;
        REP(i, Q)
        {
            if (td[i].first == s[now])
                if (td[i].second == 'L')
                    now--;
                else
                    now++;
            if (now == -1 or now == N)
                break;
        }
        if (now == -1)
            A[0] = tmp;
        else
            A[1] = tmp;
    }
    int L = 0;
    now = A[0];
    REP(i, Q)
    {
        if (td[i].first == s[now])
            if (td[i].second == 'L')
                now--;
            else
                now++;
        if (now == -1 or now == N)
            break;
    }
    if (now == -1)
        L = A[0] + 1;
    now = A[1];
    REP(i, Q)
    {
        if (td[i].first == s[now])
            if (td[i].second == 'L')
                now--;
            else
                now++;
        if (now == -1 or now == N)
            break;
    }
    if (now == -1)
        L = A[1] + 1;
    // cout << L << endl;

    A[0] = 0;
    A[1] = N - 1;
    while (A[1] - A[0] > 1)
    {
        tmp = (A[0] + A[1]) / 2;
        now = tmp;
        REP(i, Q)
        {
            if (td[i].first == s[now])
                if (td[i].second == 'L')
                    now--;
                else
                    now++;
            if (now == -1 or now == N)
                break;
        }
        if (now == N)
            A[1] = tmp;
        else
            A[0] = tmp;
    }
    int R = 0;
    now = A[1];
    REP(i, Q)
    {
        if (td[i].first == s[now])
            if (td[i].second == 'L')
                now--;
            else
                now++;
        if (now == -1 or now == N)
            break;
    }
    if (now == N)
        R = N - A[1];
    now = A[0];
    REP(i, Q)
    {
        if (td[i].first == s[now])
            if (td[i].second == 'L')
                now--;
            else
                now++;
        if (now == -1 or now == N)
            break;
    }
    if (now == N)
        R = N - A[0];
    // cout << R << endl;
    cout << max(0LL, N - L - R) << endl;
    // system("pause");
}