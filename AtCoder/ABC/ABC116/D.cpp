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
const long long INF = 1LL << 58;
struct Edge
{
    ll s, t, d;
};
typedef vector<vector<Edge>> Graph;
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

typedef priority_queue<pii, vector<pii>, greater<pii>> eat_;
typedef priority_queue<pii> not_eat_;

signed main()
{
    int N, K;
    cin >> N >> K;
    vpii sushi;
    sushi.resize(N);
    int t, d;
    REP(i, N)
    {
        cin >> t >> d;
        sushi[i] = make_pair(d, t);
    }

    //食べる候補を保持するqueue
    eat_ eat;
    not_eat_ not_eat;
    //食べる個数
    map<int, int> used_list;

    //おいしさ降順に並び替える
    sort(sushi.begin(), sushi.end(), greater<pii>());

    int var;
    int deli = 0;
    int ans = 0;
    // 美味しいものから貪欲に選ぶ。
    REP(i, N)
    {
        if (i < K)
        {
            deli = deli + sushi[i].first;
            if (++used_list[sushi[i].second] > 1) //2個以上あるやつは交換候補へ
                eat.push(sushi[i]);
        }
        else
        {
            if (used_list.find(sushi[i].second) == used_list.end()) //食べるリストにない種類を一個だけ交換候補へ。キーの存在で判断できる。
            {
                used_list[sushi[i].second] = 0;
                not_eat.push(sushi[i]);
            }
        }
    }

    //スコア計算
    var = 0;
    REP(i, 100001)
    {
        if (used_list[i] != 0)
            var++;
    }
    chmax(ans, deli + var * var);

    //種類が増えるように、食べるものリストのまずいやつと食べないものリストの美味しいやつを交換していく。
    while (true)
    {
        if (eat.empty() or not_eat.empty())
            break;
        deli -= eat.top().first;
        eat.pop();
        deli += not_eat.top().first;
        not_eat.pop();

        var++;
        chmax(ans, deli + var * var);
    }

    cout << ans << endl;
    system("pause");
}