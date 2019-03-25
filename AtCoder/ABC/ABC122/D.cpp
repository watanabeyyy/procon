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

ll mod = 1000000007;

signed main()
{
    //AGC,ACG,GAC,A*GC,AG*Cを含まない文字列をdpで数えていく
    //後ろから3文字分の組み合わせをmapで格納しておけば次に選べる文字の組み合わせも決められる
    int N;
    cin >> N;
    map<string, int> dp;
    string moji = "AGCT";
    string key_s = "";
    REP(i, 4) //高々4^3のループ
    {
        key_s = "";
        key_s += moji[i];
        REP(j, 4)
        {
            key_s = key_s.substr(0, 1);
            key_s += moji[j];
            REP(k, 4)
            {
                key_s = key_s.substr(0, 2);
                key_s += moji[k];
                if (key_s == "AGC" or key_s == "GAC" or key_s == "ACG")
                    dp[key_s] = 0;
                else
                    dp[key_s] = 1;
            }
        }
    }

    map<string, int> temp_dp;
    string key_n;
    REP(t, N - 3)
    {
        temp_dp = dp; //コピー
        REP(i, 4)     //初期化
        {
            key_s = "";
            key_s += moji[i];
            REP(j, 4)
            {
                key_s = key_s.substr(0, 1);
                key_s += moji[j];
                REP(k, 4)
                {
                    key_s = key_s.substr(0, 2);
                    key_s += moji[k];
                    dp[key_s] = 0;
                }
            }
        }

        REP(i, 4)
        {
            key_s = "";
            key_s += moji[i];
            REP(j, 4)
            {
                key_s = key_s.substr(0, 1);
                key_s += moji[j];
                REP(k, 4)
                {
                    key_s = key_s.substr(0, 2);
                    key_s += moji[k]; //遷移元の文字列

                    REP(l, 4)
                    {
                        key_n = key_s;
                        key_n += moji[l]; //遷移先の文字列
                        //AGC,ACG,GAC,A*GC,AG*Cではないか
                        if (key_n[1] == 'A' and key_n[2] == 'G' and key_n[3] == 'C')
                            continue;
                        if (key_n[1] == 'A' and key_n[2] == 'C' and key_n[3] == 'G')
                            continue;
                        if (key_n[1] == 'G' and key_n[2] == 'A' and key_n[3] == 'C')
                            continue;
                        if (key_n[0] == 'A' and key_n[2] == 'G' and key_n[3] == 'C')
                            continue;
                        if (key_n[0] == 'A' and key_n[1] == 'G' and key_n[3] == 'C')
                            continue;
                        dp[key_n.substr(1, 3)] += temp_dp[key_s];
                        dp[key_n.substr(1, 3)] %= mod;
                    }
                }
            }
        }
    }
    // REP(i, 4)
    // {
    //     key_s = "";
    //     key_s += moji[i];
    //     REP(j, 4)
    //     {
    //         key_s = key_s.substr(0, 1);
    //         key_s += moji[j];
    //         REP(k, 4)
    //         {
    //             key_s = key_s.substr(0, 2);
    //             key_s += moji[k];
    //             cout << key_s << ":" << dp[key_s] << endl;
    //         }
    //     }
    // }
    ll ans = 0;
    REP(i, 4)
    {
        key_s = "";
        key_s += moji[i];
        REP(j, 4)
        {
            key_s = key_s.substr(0, 1);
            key_s += moji[j];
            REP(k, 4)
            {
                key_s = key_s.substr(0, 2);
                key_s += moji[k];
                ans += dp[key_s];
                ans %= mod;
            }
        }
    }

    cout << ans << endl;
    system("pause");
}