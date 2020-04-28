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

struct Node
{
    int key;
    Node *parent, *left, *right;
};

Node *root;
void insert(int no)
{
    Node *now = root;
    Node *tmp = new Node;
    tmp->key = no;
    tmp->parent = NULL;
    tmp->left = NULL;
    tmp->right = NULL;
    while (1)
    {
        if (no < now->key)
        {
            if (now->left == NULL)
            {
                now->left = tmp;
                tmp->parent = now;
                break;
            }
            else
            {
                now = now->left;
            }
        }
        else if (no > now->key)
        {
            if (now->right == NULL)
            {
                now->right = tmp;
                tmp->parent = now;
                break;
            }
            else
            {
                now = now->right;
            }
        }
        else
            break;
    }
}
Node *find(int n)
{
    Node *tmp = root;
    while (1)
    {
        if (n == tmp->key)
        {
            cout << "yes" << endl;
            return tmp;
        }
        else if (n < tmp->key)
        {
            if (tmp->left == NULL)
            {
                cout << "no" << endl;
                return NULL;
            }
            tmp = tmp->left;
        }
        else if (n > tmp->key)
        {
            if (tmp->right == NULL)
            {
                cout << "no" << endl;
                return NULL;
            }
            tmp = tmp->right;
        }
    }
}
bool nextflg = false;
Node *nex;
void getmiddlenext(Node *n, Node *bef)
{
    if (n->left != NULL)
    {
        getmiddlenext(n->left, bef);
    }
    if (nextflg)
    {
        nex = n;
        nextflg = false;
    }
    if (n == bef)
    {
        nextflg = true;
    }
    if (n->right != NULL)
    {
        getmiddlenext(n->right, bef);
    }
}
void modea(Node *t)
{
    Node *p = t->parent;
    if (p->left == t)
        p->left = NULL;
    else if (p->right == t)
        p->right = NULL;
}
void modeb(Node *t)
{
    Node *p = t->parent;
    if (t->left != NULL)
    {
        if (p->left == t)
        {
            p->left = t->left;
            t->left->parent = p;
        }
        else if (p->right == t)
        {
            p->right = t->left;
            t->left->parent = p;
        }
    }
    else if (t->right != NULL)
    {
        if (p->left == t)
        {
            p->left = t->right;
            t->right->parent = p;
        }
        else if (p->right == t)
        {
            p->right = t->right;
            t->right->parent = p;
        }
    }
}

void del(int n)
{
    Node *t = find(n);
    if (t != NULL)
    {
        if (t->left == NULL && t->right == NULL)
            modea(t);
        else if (t->left != NULL && t->right != NULL)
        {
            nextflg = false;
            getmiddlenext(t, t);
            t->key = nex->key;
            if (t->left == NULL && t->right == NULL)
                modea(nex);
            else
                modeb(nex);
        }
        else
            modeb(t);
        delete t;
    };
}

bool first;
void middle(Node *node)
{
    if (node->left != NULL)
        middle(node->left);
    if (first)
    {
        cout << node->key;
        first = false;
    }
    else
        cout << " " << node->key;
    if (node->right != NULL)
        middle(node->right);
}
void head(Node *node)
{
    if (first)
    {
        cout << node->key;
        first = false;
    }
    else
        cout << " " << node->key;
    if (node->left != NULL)
        head(node->left);
    if (node->right != NULL)
        head(node->right);
}

signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    int N = 8;
    vi a = {8, 2, 3, 7, 22, 1};

    root = new Node;
    root->key = -1;
    root->parent = NULL;
    root->left = NULL;
    root->right = NULL;

    REP(i, a.size())
    {
        if (root->key == -1)
            root->key = a[i];
        else
            insert(a[i]);
    }
    find(1);
    find(2);
    find(3);
    find(4);
    find(5);
    find(6);
    find(7);
    find(8);
    first = false;
    middle(root);
    cout << endl;
    first = false;
    head(root);
    cout << endl;
    del(3);
    del(7);
    first = false;
    middle(root);
    cout << endl;
    first = false;
    head(root);
    cout << endl;

    return 0;
}