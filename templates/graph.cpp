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
int tim = 0;
int f[101];
int e[101];
int dis[101];
int color[101];
vector<int> graph_list[101];

void dfs_visit(int a)
{
    REP(i, N)
    {
        if (mem[a][i] == 1 && f[i] == 0)
        {
            tim++;
            f[i] = tim;
            dfs_visit(i);
        }
    }
    if (e[a] == 0)
    {
        tim++;
        e[a] = tim;
    }
}

void dfs()
{
    tim++;
    f[0] = tim;
    REP(i, N)
    {
        dfs_visit(i);
    }
}
void dfss()
{
    stack<int> s;
    REP(i, N)
    {
        if (f[i] == 0)
        {
            s.push(i);
            tim++;
            f[i] = tim;
        }
        while (!s.empty())
        {
            int t = s.top();
            bool flg = true;
            REP(j, N)
            {
                if (mem[t][j] == 1 && f[j] == 0)
                {
                    s.push(j);
                    tim++;
                    f[j] = tim;
                    flg = false;
                    break;
                }
            }
            if (flg)
            {
                s.pop();
                tim++;
                e[t] = tim;
            }
        }
    }
}

void dsll(int a, int c)
{
    color[a] = c;
    REP(i, graph_list[a].size())
    {
        int tmp = graph_list[a][i];
        dsll(tmp, c);
    }
}

void dfsl()
{
    int tmp = 0;
    REP(i, N)
    {
        if (color[i] == -1)
        {
            dsll(i, tmp);
            tmp++;
        }
    }
}

void bfs()
{
    queue<int> q;
    int d = 0;
    dis[0] = d;
    q.push(0);
    while (!q.empty())
    {
        int tmp = q.front();
        d = dis[tmp];
        q.pop();
        REP(j, N)
        {
            if (mem[tmp][j] == 1 && dis[j] == -1)
            {
                q.push(j);
                dis[j] = d + 1;
            }
        }
    }
}

signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
    int K;
    cin >> N >> K;
    REP(i, N)
    {
        color[i] = -1;
    }
    REP(i, K)
    {
        int a, b;
        cin >> a >> b;
        graph_list[a].push_back(b);
    }

    pair<int, int> query[101];
    cin >> K;
    REP(i, K)
    {
        int a, b;
        cin >> a >> b;
        query[i].first = a;
        query[i].second = b;
    }

    dfsl();

    REP(i, K)
    {
        if (color[query[i].first] == color[query[i].second])
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}