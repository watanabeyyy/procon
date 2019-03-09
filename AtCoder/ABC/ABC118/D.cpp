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
template <class string>
inline bool chmax(string &a, string b)
{
    if (a == "-")
    {
        a = b;
        return true;
    }
    if (a.size() < b.size())
    {
        a = b;
        return true;
    }
    else if (a.size() == b.size() and a < b)
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

int main()
{
    int N, M;
    cin >> N >> M;
    int T[10];
    T[1] = 2;
    T[2] = 5;
    T[3] = 5;
    T[4] = 4;
    T[5] = 5;
    T[6] = 6;
    T[7] = 3;
    T[8] = 7;
    T[9] = 6;
    string A[9];
    REP(i, M)
    cin >> A[i];

    string dp[10001];
    REP(i, 10001)
    {
        dp[i] = "-";
    }
    dp[0] = "";
    REP(i, N + 1)
    {
        REP(j, M)
        {
            if (i - T[stoi(A[j])] >= 0)
            {
                if (dp[i - T[stoi(A[j])]] != "-")
                    chmax(dp[i], dp[i - T[stoi(A[j])]] + A[j]);
            }
        }
    }
    cout << dp[N] << endl;

    // system("pause");
}