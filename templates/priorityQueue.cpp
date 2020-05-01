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
int parent(int i)
{
    return (i + 1) / 2 - 1;
};
int left(int i)
{
    return 2 * (i + 1) - 1;
};
int right(int i)
{
    return 2 * (i + 1);
};

vi v;

void maxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int maxidx = i;
    if (l < v.size())
        if (v[l] > v[maxidx])
            maxidx = l;
    if (r < v.size())
        if (v[r] > v[maxidx])
            maxidx = r;
    if (maxidx != i)
    {
        int tmp = v[i];
        v[i] = v[maxidx];
        v[maxidx] = tmp;
        maxHeapify(maxidx);
    }
};

void insert(int a)
{
    v.push_back(a);
    int p = parent(v.size() - 1);
    if (p >= 0)
    {
        maxHeapify(p);
    }
}

void extract()
{
    // cout << v[0] << endl;
    v[0] = v[v.size() - 1];
    v.erase(v.end() - 1);
    maxHeapify(0);
}
signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    insert(8);
    REP(i, v.size())
    cout << v[i] << " ";
    cout << endl;
    insert(2);
    REP(i, v.size())
    cout << v[i] << " ";
    cout << endl;
    extract();
    REP(i, v.size())
    cout << v[i] << " ";
    cout << endl;
    insert(10);
    REP(i, v.size())
    cout << v[i] << " ";
    cout << endl;
    extract();
    REP(i, v.size())
    cout << v[i] << " ";
    cout << endl;
    insert(11);
    REP(i, v.size())
    cout << v[i] << " ";
    cout << endl;
    extract();
    REP(i, v.size())
    cout << v[i] << " ";
    cout << endl;
    extract();
    REP(i, v.size())
    cout << v[i] << " ";
    cout << endl;

    return 0;
}