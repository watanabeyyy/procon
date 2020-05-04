#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(a) (a).begin(), (a).end()
typedef vector<int> vi;
const int INF = 1LL << 58;
const int MOD = 1000000007;
const int MAX_N = 200100;

signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
    int V, E;
    cin >> V >> E;
    int G[110][110];
    REP(i, V)
    {
        REP(j, V)
        {
            G[i][j] = INF;
        }
        G[i][i] = 0;
    }
    REP(i, E)
    {
        int s, t, d;
        cin >> s >> t >> d;
        G[s][t] = d;
    }
    REP(i, V)
    {
        REP(j, V)
        {
            REP(k, V)
            {
                int a = G[j][k];
                int b = G[j][i] + G[i][k];
                if (a > b)
                {
                    G[j][k] = b;
                }
                else
                {
                    G[j][k] = a;
                }
            }
        }
    }

    REP(i, V)
    {
        if (G[i][i] < 0)
        {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }

    REP(i, V)
    {
        REP(j, V)
        {
            int t = G[i][j];
            if (t == INF)
                cout << "INF"
                     << " ";
            else
                cout << G[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}