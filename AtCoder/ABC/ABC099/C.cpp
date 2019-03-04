#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define ALL(a) (a).begin(), (a).end()
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
const ll INF = (1ll << 60);
typedef pair<ll, ll> pii;
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

int main()
{
    int dp[100001];
    int N;
    cin >> N;
    REP(i, 100002)
    {
        dp[i] = -1;
    }
    dp[0] = 0;
    vi all_list;
    vi now_list;
    all_list.push_back(1);
    int temp = 6;
    while (true)
    {
        all_list.push_back(temp);
        temp = temp * 6;
        if (temp > 100001)
            break;
    }
    temp = 9;
    while (true)
    {
        all_list.push_back(temp);
        temp = temp * 9;
        if (temp > 100001)
            break;
    }
    sort(ALL(all_list));
    REP(i, 100002)
    {
        if (i == 0)
            continue;
        if (i == all_list[0])
        {
            now_list.push_back(i);
            all_list.erase(all_list.begin());
        }
        int min_temp = 1000000;
        REP(j, now_list.size())
        {
            min_temp = min(min_temp, dp[i - now_list[j]] + 1);
        }
        dp[i] = min_temp;
    }
    cout << dp[N] << endl;
    system("pause");
}