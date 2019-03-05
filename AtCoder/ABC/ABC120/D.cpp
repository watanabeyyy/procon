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

#define MAX_N 100001

ll uf_par[MAX_N];  //親
ll uf_rank[MAX_N]; //木の深さ
ll uf_size[MAX_N]; //木のサイズ

//初期化、深さ0のn個の親を作る
void init(ll n)
{
    for (int i = 0; i < n; i++)
    {
        uf_par[i] = i;
        uf_rank[i] = 0;
        uf_size[i] = 1;
    }
}

//木の根を求める find
ll find(ll x)
{
    if (uf_par[x] == x) //親が自分なら根
        return x;
    else //自分の親の親を探しに行く
        return uf_par[x] = find(uf_par[x]);
}

//xとyの集合を併合　union
ll unite(ll x, ll y)
{
    ll num;
    x = find(x);
    y = find(y);
    num = uf_size[x] * uf_size[y];

    if (uf_rank[x] < uf_rank[y]) //深いほうの根を使う
    {
        uf_par[x] = y;
        uf_size[y] = uf_size[y] + uf_size[x];
    }
    else
    {
        uf_par[y] = x;
        uf_size[x] = uf_size[x] + uf_size[y];
        if (uf_rank[x] == uf_rank[y]) //深さが同じなら、併合後に1深くなる
            uf_rank[x]++;
    }
    return num;
}

//xとyが同じ集合かどうか
bool same(ll x, ll y)
{
    return find(x) == find(y);
}

int main()
{
    ll N, M;
    cin >> N >> M;
    ll AB[MAX_N][2];
    REP(i, M)
    {
        cin >> AB[i][0] >> AB[i][1];
    }
    init(N);
    vi ans;
    ans.push_back(N * (N - 1) / 2);
    int A, B;
    for (int i = M - 1; i >= 0; i--)
    {
        A = AB[i][0];
        B = AB[i][1];
        if (same(A, B))
        {
            ans.push_back(ans[ans.size() - 1]);
            continue;
        }
        ans.push_back(ans[ans.size() - 1] - unite(A, B));
    }
    REP(i, M)
    {
        cout << ans[ans.size() - 2 - i] << endl;
    }

    system("pause");
}