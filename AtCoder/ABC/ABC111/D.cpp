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
    int N;
    vpii xy;
    cin >> N;
    xy.resize(N);
    REP(i, N)
    cin >> xy[i].first >> xy[i].second;

    //abs(x)+abs(y)のパリティが全部同じかチェック
    bool p = ((abs(xy[0].first) + abs(xy[0].second)) % 2 == 0);
    REP(i, N - 1)
    {
        if (p != ((abs(xy[i + 1].first) + abs(xy[i + 1].second)) % 2 == 0))
        {
            cout << -1 << endl;
            return 0;
        }
    }

    vi arm;
    if (p)
        arm.push_back(1);
    int tmp = 1;
    REP(i, 39)
    {
        arm.push_back(tmp);
        tmp *= 2;
    }
    sort(arm.begin(), arm.end(), greater<int>());
    cout << arm.size() << endl;
    REP(i, arm.size())
    cout << arm[i] << " ";
    cout << endl;

    int nowA, nowB;
    bool modeA, modeB;
    int dirA, dirB;

    REP(i, N)
    {
        nowA = 0;
        nowB = 0;
        dirA = xy[i].first + xy[i].second;
        dirB = xy[i].first - xy[i].second;
        REP(i, arm.size())
        {
            if (nowA < dirA)
            {
                nowA += arm[i];
                modeA = true;
            }
            else
            {
                nowA -= arm[i];
                modeA = false;
            }
            if (nowB < dirB)
            {
                nowB += arm[i];
                modeB = true;
            }
            else
            {
                nowB -= arm[i];
                modeB = false;
            }
            if (modeA and modeB)
                cout << 'R';
            if (modeA and !modeB)
                cout << 'U';
            if (!modeA and !modeB)
                cout << 'L';
            if (!modeA and modeB)
                cout << 'D';
        }
        cout << endl;
    }

    // system("pause");
}
