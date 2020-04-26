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

vi A = {1, 5, 7, 10, 21};
vi B = {2, 4, 17, 8};
bool fn(int i, int M)
{
    if (i >= A.size())
        return false;
    if (M == 0)
        return true;
    return fn(i + 1, M - A[i]) || fn(i + 1, M);
}

signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    REP(i, B.size())
    {
        if (fn(0, B[i]))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}