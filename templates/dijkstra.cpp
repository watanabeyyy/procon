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
int t[101];

vector<pair<int, int>> mem[101];

vector<pair<int, int>> mst;

typedef pair<int, pair<int, int>> mypair;
bool operator>(const mypair a, const mypair b) { return a.first > b.first; }; //演算子オーバーロード

void dijkstra()
{
    REP(i, N)
    t[i] = -1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    t[0] = 0;
    REP(i, mem[0].size())
    {
        int v = mem[0][i].first;
        int c = mem[0][i].second;
        pq.push(make_pair(t[0] + c, v));
    }

    while (!pq.empty())
    {
        pair<int, int> tmp = pq.top();
        pq.pop();
        //コストが確定していないノードから最小のコストで行ける物を探す
        if (t[tmp.second] == -1)
        {
            //ノードとコストの確定
            t[tmp.second] = tmp.first;
            //確定したノードから行ける確定していないノードをpqに追加
            REP(i, mem[tmp.second].size())
            {
                int v = mem[tmp.second][i].first;
                int c = mem[tmp.second][i].second;
                if (t[v] == -1)
                    pq.push(make_pair(t[tmp.second] + c, v));
            }
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
        int a, b;
        cin >> a >> b;
        REP(j, b)
        {
            int v, c;
            cin >> v >> c;
            mem[a].push_back(make_pair(v, c));
        }
    }

    dijkstra();
    REP(i, N)
    {
        cout << i << " " << t[i] << endl;
    }

    return 0;
}