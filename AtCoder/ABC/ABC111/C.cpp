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

signed main()
{
    int N;
    cin >> N;
    //mapで/と\を数え上げ
    unordered_map<int, int> A, B;
    int key;
    REP(i, N)
    {
        cin >> key;
        if (i % 2 == 0)
            A[key]++;
        else
            B[key]++;
    }

    //valueを"変える個数"に変換
    for (auto it = A.begin(); it != A.end(); ++it)
        it->second = N / 2 + N % 2 - it->second;
    for (auto it = B.begin(); it != B.end(); ++it)
        it->second = N / 2 - it->second;

    //Aについて、変える個数が一番少ないものと二番目に少ないものを調べる
    //secondの初期値は下の感じにしておくと数字が一種類のケースの処理が後で楽になる。
    //もっと簡単にソートできるのでは???
    pii fA, sA;
    fA.second = N / 2 + N % 2;
    sA.second = N / 2 + N % 2;
    int value;
    for (auto it = A.begin(); it != A.end(); it++)
    {
        value = it->second;
        if (value < fA.second)
        {
            sA = fA;
            fA.first = it->first;
            fA.second = value;
        }
        else if (value < sA.second)
        {
            sA.first = it->first;
            sA.second = value;
        }
    }

    //Bについて
    pii fB, sB;
    fB.second = N / 2;
    sB.second = N / 2;
    for (auto it = B.begin(); it != B.end(); it++)
    {
        value = it->second;
        if (value < fB.second)
        {
            sB = fB;
            fB.first = it->first;
            fB.second = value;
        }
        else if (value < sB.second)
        {
            sB.first = it->first;
            sB.second = value;
        }
    }

    //同じ数字じゃなきゃ最小の和、同じなら2組試して小さいほう
    if (fA.first != fB.first)
        cout << fA.second + fB.second << endl;
    else
        cout << min(fA.second + sB.second, sA.second + fB.second);

    system("pause");
}