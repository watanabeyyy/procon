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

signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    string S = "\\\\///\\_/\\/\\\\\\\\/_/\\\\///__\\\\\\_\\\\/_\\/_/\\";
    stack<int> sta;
    stack<pair<int, int>> ans;
    REP(i, S.size())
    {
        if (S[i] == '\\')
        {
            sta.push(i);
        }
        else if (sta.empty())
            continue;
        else if (S[i] == '/')
        {
            ans.push(make_pair(sta.top(), i - sta.top()));
            sta.pop();
            while (ans.size() > 1)
            {
                pair<int, int> tmp = ans.top();
                ans.pop();
                if (ans.top().first > tmp.first)
                {
                    pair<int, int> newpair = make_pair(tmp.first, ans.top().second + tmp.second);
                    ans.pop();
                    ans.push(newpair);
                }
                else
                {
                    ans.push(tmp);
                    break;
                }
            }
        }
    }
    vi anss;
    int cnt = 0;
    while (ans.empty() == 0)
    {
        cnt += ans.top().second;
        anss.push_back(ans.top().second);
        ans.pop();
    }

    cout << cnt << endl;
    cout << anss.size() << " ";
    REP(i, anss.size())
    {
        cout << anss[anss.size() - 1 - i] << " ";
    }
    cout << endl;
    return 0;
}