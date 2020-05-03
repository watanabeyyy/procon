#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(a) (a).begin(), (a).end()
typedef vector<int> vi;
const int INF = 1LL << 58;
const int MOD = 1000000007;
const int MAX_N = 200100;

int uf_par[MAX_N];  //親
int uf_rank[MAX_N]; //木の深さ

//初期化、深さ0のn個の親を作る
void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        uf_par[i] = i;
        uf_rank[i] = 0;
    }
}

//木の根を求める find
int find(int x)
{
    if (uf_par[x] == x) //親が自分なら根
        return x;
    else //自分の親の親を探しに行く
        return uf_par[x] = find(uf_par[x]);
}

//xとyの集合を併合　union
void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) //根が同じなら、すでに同一グループ
        return;

    if (uf_rank[x] < uf_rank[y]) //深いほうの根を使う
    {
        uf_par[x] = y;
    }
    else
    {
        uf_par[y] = x;
        if (uf_rank[x] == uf_rank[y]) //深さが同じなら、併合後に1深くなる
            uf_rank[x]++;
    }
}

//xとyが同じ集合かどうか
bool same(int x, int y)
{
    return find(x) == find(y);
}