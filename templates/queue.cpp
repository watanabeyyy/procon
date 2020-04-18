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

typedef struct pp
{
    string name;
    int time;
} P;

#define MAX 100010
P A[MAX];
int head = 0;
int tail = 0;

P pop()
{
    int tmp = head;
    head = (head + 1) % MAX;
    return A[tmp];
}

void push(P a)
{
    A[tail] = a;
    tail = (tail + 1) % MAX;
}

signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    int N = 5;
    int q = 100;
    string S[5] = {"p1", "p2", "p3", "p4", "p5"};
    int T[5] = {150, 80, 200, 350, 20};
    REP(i, N)
    {
        A[i].name = S[i];
        A[i].time = T[i];
        tail++;
    }
    int cnt = 0;
    while (head != tail)
    {
        P tmpp = pop();
        int tmpt = 100;
        int tmp = min(tmpp.time, tmpt);
        tmpt -= tmp;
        tmpp.time -= tmp;
        cnt += tmp;
        if (tmpp.time == 0)
        {
            cout << tmpp.name << " " << cnt << endl;
        }
        else
        {
            push(tmpp);
        }
    }
    return 0;
}