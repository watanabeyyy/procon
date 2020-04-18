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

typedef struct Node
{
    int key;
    Node *prev;
    Node *next;
} node;

node *nil = (node *)malloc(sizeof(node));

void insert(node *a)
{
    a->prev = nil;
    a->next = nil->next;
    nil->next->prev = a;
    nil->next = a;
}

void del(int a)
{
    node *tmp = nil->next;
    while (tmp != nil)
    {
        if (tmp->key == a)
        {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            free(tmp);
            break;
        }
        tmp = tmp->next;
    }
}

signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    int N = 7;
    string S[N] = {"insert",
                   "insert",
                   "insert",
                   "insert",
                   "delete",
                   "insert",
                   "delete"};
    int T[N] = {
        5,
        2,
        3,
        1,
        3,
        6,
        5,
    };
    nil->prev = nil;
    nil->next = nil;

    REP(i, N)
    {
        if (S[i] == "insert")
        {
            node *n = (node *)malloc(sizeof(node));
            n->key = T[i];
            insert(n);
        }
        else if (S[i] == "delete")
            del(T[i]);
    }
    node *tmp = nil->next;
    while (tmp != nil)
    {
        cout << tmp->key << endl;
        tmp = tmp->next;
    }
    return 0;
}