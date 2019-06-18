#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define UM unordered_map
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

signed main()
{
    string S;
    cin >> S;
    bool a = false;
    bool b = false;
    if (stoi(S.substr(0, 2)) <= 12 and stoi(S.substr(0, 2)) > 0)
        b = true;
    if (stoi(S.substr(2, 2)) <= 12 and stoi(S.substr(2, 2)) > 0)
        a = true;
    if (a and b)
        cout << "AMBIGUOUS" << endl;
    else if (a)
        cout << "YYMM" << endl;
    else if (b)
        cout << "MMYY" << endl;
    else
        cout << "NA" << endl;

    // system("pause");
}