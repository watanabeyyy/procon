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

int A[110];
int head = -1;

int pop()
{
    head--;
    return A[head + 1];
}

void push(int a)
{
    head++;
    A[head] = a;
}

signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    string S = "1 2 + 4 3 - *";
    int tmp = 0;
    int length = 0;
    bool flg = 0;
    while (tmp < S.size())
    {
        length++;
        if (tmp + length >= S.size())
            flg = 1;
        else if (S[tmp + length] == ' ')
            flg = 1;
        else
            flg = 0;
        if (flg)
        {
            string ss = S.substr(tmp, length);
            if (ss == "+")
            {
                int a = pop();
                int b = pop();
                push(a + b);
            }
            else if (ss == "-")
            {
                int a = pop();
                int b = pop();
                push(b - a);
            }
            else if (ss == "*")
            {
                int a = pop();
                int b = pop();
                push(b * a);
            }
            else
            {
                int num = stoi(ss);
                push(num);
            }
            tmp += length + 1;
            length = 0;
        }
    }
    cout << pop() << endl;
    return 0;
}