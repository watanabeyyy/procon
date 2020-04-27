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

struct node
{
    //左子、右兄弟の表現
    //それぞれ一番左の節点を示す
    int p, l, r;
};

node nod[100010];
int calDepth(node no)
{
    int ans = 0;
    while (no.p != -1)
    {
        ans++;
        no = nod[no.p];
    }
    return ans;
}

string who(node no)
{
    if (no.p == -1)
        return "root";
    if (no.l == -1)
        return "leaf";
    return "internal node";
}

signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
    int N;
    cin >> N;
    REP(i, N)
    {
        nod[i].p = -1;
        nod[i].l = -1;
        nod[i].r = -1;
    }
    REP(i, N)
    {
        int idx, num, child;
        cin >> idx >> num;
        REP(j, num)
        {
            cin >> child;
            nod[child].p = idx;
            int tmp = nod[idx].l;
            if (tmp == -1)
            {
                nod[idx].l = child;
            }
            else
            {
                while (1)
                {
                    if (nod[tmp].r == -1)
                    {
                        nod[tmp].r = child;
                        break;
                    }
                    tmp = nod[tmp].r;
                }
            }
        }
    }
    REP(i, N)
    {
        cout << "node " << i << ": parent = " << nod[i].p;
        cout << ", depth = " << calDepth(nod[i]) << ", " << who(nod[i]);
        cout << ", [";
        int tmp = nod[i].l;
        if (tmp != -1)
            cout << tmp;
        while (tmp != -1)
        {
            tmp = nod[tmp].r;
            if (tmp == -1)
                break;
            cout << ", " << tmp;
        }
        cout << "]" << endl;
    }

    return 0;
}