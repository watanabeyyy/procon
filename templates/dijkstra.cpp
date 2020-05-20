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

struct edge
{
    int to;
    int cost;
};

// <コスト, 頂点の番号>
using P = pair<int, int>;

int V;                 //ノード数
vector<edge> G[10000]; //グラフ
int d[10000];          //最小コストを保存する配列

void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P>> que; //vector<P>の形でコスト昇順
    fill(d, d + V, INF);                          //コストをINFで初期化
    d[s] = 0;                                     //初期値へのコストは0
    que.push(P(0, s));                            //初期値<コスト、頂点番号>d

    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first)
            continue;

        for (int i = 0; i < G[v].size(); ++i) //vからいけるところ
        {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) //コストが更新できればqueueに追加
            {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

signed main()
{
    cin >> V;
    int E;
    cin >> E;
    for (int i = 0; i < E; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c; //a->bのコストc
        edge e = {b, c};
        G[a].push_back(e);
    }
    dijkstra(0);
    for (int i = 0; i < V; ++i)
    {
        if (d[i] != INF)
            cout << "0から" << i << "までのコスト: " << d[i] << endl;
    }
    return 0;
}