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
typedef pair<ll, priority_queue<int, vector<int>, greater<int>>> greatersushi;
typedef pair<ll, priority_queue<int>> lesssushi;
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

bool pairCompare(const pii &A, const pii &B) { return A.second > B.second; }
bool greatersushiCompare(const greatersushi &A, const greatersushi &B)
{
    return A.second.top() < B.second.top();
}
bool lesssushiCompare(const lesssushi &A, const lesssushi &B)
{
    return A.second.top() > B.second.top();
}

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
        sushi[i] = make_pair(t, d);
    }
    //おいしさ昇順に並べ替え
    sort(sushi.begin(), sushi.end(), pairCompare);

    int var;
    int deli = 0;
    int ans = 0;
    vector<greatersushi> eat;
    vector<lesssushi> not_eat;
    eat.resize(N);
    not_eat.resize(N);
    REP(i, N)
    {
        eat[i].first = i + 1;
        not_eat[i].first = i + 1;
    }

    //食べる種類リスト
    bool used_list[100001];
    REP(i, 100001)
    used_list[i] = false;

    pii tmp;
    REP(i, N)
    {
        if (i < K)
        {
            tmp = sushi[0];
            sushi.erase(sushi.begin());
            used_list[tmp.first] = true;
            eat[tmp.first - 1].second.push(tmp.second);
            deli = deli + tmp.second;
        }
        else
        {
            tmp = sushi[0];
            sushi.erase(sushi.begin());
            not_eat[tmp.first - 1].second.push(tmp.second);
        }
    }

    var = 0;
    REP(i, N + 1)
    {
        if (used_list[i])
            var++;
    }
    chmax(ans, deli + var * var);

    REP(i, N)
    {
        if (eat[i].second.empty() or (eat[i].second.size() == 1))
        {
            eat.erase(eat.begin() + i);
            i--;
            if (eat.size() == i)
                break;
        }
    }
    REP(i, N)
    {
        if (not_eat[i].second.empty() or used_list[not_eat[i].first])
        {
            not_eat.erase(not_eat.begin() + i);
            i--;
            if (not_eat.size() == i)
                break;
        }
    }

    while (true)
    {
        sort(eat.begin(), eat.end(), greatersushiCompare);
        sort(not_eat.begin(), not_eat.end(), lesssushiCompare);
        cout << var << endl;

        deli = deli - eat[0].second.top();
        eat[0].second.pop();

        deli = deli + not_eat[0].second.top();
        var++;
        chmax(ans, deli + var * var);

        if (eat[0].second.size() == 1)
        {
            if (eat.size() == 1)
                break;
        }
        eat.erase(eat.begin());
        cout << eat.size() << endl;
        cout << not_eat.size() << endl;
        if (not_eat.size() == 1)
            break;
        not_eat.erase(not_eat.begin());
    }

    cout << ans << endl;
    system("pause");
}