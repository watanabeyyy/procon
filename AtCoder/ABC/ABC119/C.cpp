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

int N, A, B, C;
vi l;
int ans = 1000000000;
void dfs(int idx, int sum_A, int sum_B, int sum_C, int cnt)
{
    if (sum_A != 0 and sum_B != 0 and sum_C != 0)
        chmin(ans, abs(sum_A - A) + abs(sum_B - B) + abs(sum_C - C) + cnt * 10);

    if (idx == N)
        return;

    if (sum_A == 0)
        dfs(idx + 1, sum_A + l[idx], sum_B, sum_C, cnt);
    else
        dfs(idx + 1, sum_A + l[idx], sum_B, sum_C, cnt + 1);
    if (sum_B == 0)
        dfs(idx + 1, sum_A, sum_B + l[idx], sum_C, cnt);
    else
        dfs(idx + 1, sum_A, sum_B + l[idx], sum_C, cnt + 1);
    if (sum_C == 0)
        dfs(idx + 1, sum_A, sum_B, sum_C + l[idx], cnt);
    else
        dfs(idx + 1, sum_A, sum_B, sum_C + l[idx], cnt + 1);
    dfs(idx + 1, sum_A, sum_B, sum_C, cnt);
}

//制約見ましょう。全探索です。
int main()
{
    cin >> N >> A >> B >> C;
    l.resize(N);
    REP(i, N)
    {
        cin >> l[i];
    }
    dfs(0, 0, 0, 0, 0);
    cout << ans << endl;
    system("pause");
}