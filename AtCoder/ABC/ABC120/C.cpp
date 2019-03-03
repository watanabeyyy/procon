#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define PQ priority_queue
#define UM unordered_map
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

string A;
vi AA;
int main()
{
    cin >> A;
    REP(i, A.size())
    {
        AA.push_back(int(A[i]));
    }
    int ans = 0;
    bool flg = true;
    while (true)
    {
        flg = true;
        REP(i, AA.size() - 1)
        {
            if (AA[i] != AA[i + 1])
            {
                AA.erase(AA.begin() + i);
                ans++;
                AA.erase(AA.begin() + i);
                ans++;
                flg = false;
                break;
            }
        }
        if (flg || AA.size() == 0)
        {
            break;
        }
    }
    cout << ans << endl;
    // system("pause");
}