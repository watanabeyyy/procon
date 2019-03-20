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

bool pairCompare(const pii &A, const pii &B) { return A.second > B.second; }

signed main()
{
    int N, K;
    cin >> N >> K;
    vpii s;
    s.resize(N);
    int t, d;
    UM<int, bool>
        sushi;
    REP(i, N)
    {
        cin >> t >> d;
        sushi[t] = false;
        s[i] = make_pair(t, d);
    }

    sort(s.begin(), s.end(), pairCompare);

    // REP(i, N)
    // cout << s[i].first << s[i].second << endl;

    int ans = 0;
    int var = 0;

    int A, B;
    int Bi;
    REP(i, K)
    {
        A = 0;
        B = 0;
        REP(j, N - i)
        {
            if (!sushi[s[j].first])
            {
                B = s[j].second + (var + 1) * (var + 1);
                Bi = j;
                break;
            }
        }
        if (!sushi[s[0].first])
            A = s[0].second + (var + 1) * (var + 1);
        else
            A = s[0].second + var * var;

        if (A >= B)
        {
            ans = ans + s[0].second;
            if (!sushi[s[0].first])
            {
                var++;
                sushi[s[0].first] = true;
            }
            s.erase(s.begin() + 0);
        }
        else
        {
            ans = ans + s[Bi].second;
            if (!sushi[s[Bi].first])
            {
                var++;
                sushi[s[Bi].first] = true;
            }
            s.erase(s.begin() + Bi);
        }
    }

    cout << ans + var * var << endl;
    //system("pause");