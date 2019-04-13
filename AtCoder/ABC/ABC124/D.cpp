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
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    vi A;
    char tmp = S[0];
    A.push_back(1);
    REP(i, S.size() - 1)
    {
        if (S[i + 1] == tmp)
            A[A.size() - 1]++;
        else
        {
            A.push_back(1);
            tmp = S[i + 1];
        }
    }
    if (A.size() == 1)
    {
        cout << N << endl;
        return 0;
    }
    int tmpp = 0;
    int ans = 0;
    int tmpf = 0;
    int tmpe = 0;
    if (S[0] == '1')
    {
        tmpp += A[0];
        tmpf = 0;
        FOR(i, 1, K * 2 + 1)
        {
            tmpe = i;
            if (tmpe >= A.size())
                break;
            tmpp += A[tmpe];
        }
        chmax(ans, tmpp);
        while (tmpe <= A.size())
        {
            tmpp -= A[tmpf];
            tmpf++;
            tmpp -= A[tmpf];
            tmpf++;

            tmpe++;
            if (tmpe == A.size())
                break;
            tmpp += A[tmpe];
            chmax(ans, tmpp);
            tmpe++;
            if (tmpe == A.size())
                break;
            tmpp += A[tmpe];
            chmax(ans, tmpp);
        }
    }
    if (S[0] == '0')
    {
        tmpp = 0;
        tmpf = -1;
        FOR(i, 0, K * 2)
        {
            tmpe = i;
            if (tmpe == A.size())
                break;
            tmpp += A[tmpe];
        }
        chmax(ans, tmpp);
        while (tmpe <= A.size())
        {
            if (tmpf > -1)
            {
                tmpp -= A[tmpf];
            }
            tmpf++;
            tmpp -= A[tmpf];
            tmpf++;

            tmpe++;
            if (tmpe == A.size())
                break;
            tmpp += A[tmpe];
            chmax(ans, tmpp);
            tmpe++;
            if (tmpe == A.size())
                break;
            tmpp += A[tmpe];
            chmax(ans, tmpp);
        }
    }
    cout << ans << endl;
    // system("pause");
}