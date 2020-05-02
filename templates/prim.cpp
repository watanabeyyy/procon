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
int N;
int mem[101][101];
int t[101];

vector<pair<int, int>> mst;

typedef pair<int, pair<int, int>> mypair;
bool operator>(const mypair a, const mypair b) { return a.first > b.first; }; //演算子オーバーロード

void prim()
{
    REP(i, N)
    t[i] = -1;

    priority_queue<mypair, vector<mypair>, greater<mypair>> pq;

    t[0] = 1;
    REP(j, N)
    {
        if (mem[0][j] != -1)
            pq.push(make_pair(mem[0][j], make_pair(0, j)));
    }

    while (mst.size() != N - 1)
    {
        mypair tmp = pq.top();
        pair<int, int> tp = tmp.second;
        if (t[tp.second] == -1)
        {
            t[tp.second] = 1;
            mst.push_back(tp);
            pq.pop();
            REP(j, N)
            {
                if (mem[tp.second][j] != -1)
                    pq.push(make_pair(mem[tp.second][j], make_pair(tp.second, j)));
            }
        }
        else
        {
            pq.pop();
        }
    }
}

signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
    cin >> N;
    REP(i, N)
    {
        REP(j, N)
        {
            cin >> mem[i][j];
        }
    }

    prim();
    int ans = 0;

    REP(i, mst.size())
    {
        cout << mst[i].first << " " << mst[i].second << endl;
        ans += mem[mst[i].first][mst[i].second];
    }

    cout << ans << endl;

    return 0;
}