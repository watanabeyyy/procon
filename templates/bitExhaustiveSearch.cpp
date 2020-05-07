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
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    int H, W, K;
    cin >> H >> W >> K;
    int C[11][1001];
    for (int i = 1; i <= H; i++)
    {
        string S;
        cin >> S;
        for (int j = 1; j <= W; j++)
        {
            if (S.at(j - 1) == '0')
                C[i][j] = 0;
            else if (S.at(j - 1) == '1')
                C[i][j] = 1;
        }
    }
    REP(i, H)
    C[i][0] = 0;

    REP(i, W)
    C[0][i] = 0;

    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            C[i][j] = C[i][j] + C[i - 1][j] + C[i][j - 1] - C[i - 1][j - 1];
        }
    }

    int ans = INF;
    for (int bit = 0; bit < (1 << H - 1); ++bit)
    {
        int tmp[11][1001];
        int idx = 0;
        int befidx = 0;
        REP(i, H - 1)
        {
            if (bit & (1 << i))
            {
                for (int j = 0; j <= W; j++)
                {
                    tmp[idx][j] = C[i + 1][j] - C[befidx][j];
                }
                idx++;
                befidx = i + 1;
            }
        }
        for (int j = 0; j <= W; j++)
            tmp[idx][j] = C[H][j] - C[befidx][j];
        int tmpans = idx;
        int tmpw = 0;
        for (int i = 1; i < W; i++)
        {
            REP(j, idx + 1)
            {
                if (tmp[j][i] - tmp[j][tmpw] > K)
                {
                    if (i - 1 == tmpw)
                    {
                        tmpans += INF;
                    }
                    else
                        tmpans++;
                    tmpw = i - 1;
                    break;
                }
            }
        }
        REP(j, idx + 1)
        {
            if (tmp[j][W] - tmp[j][tmpw] > K)
            {
                if (W - 1 == tmpw)
                {
                    tmpans += INF;
                }
                else
                    tmpans++;
                break;
            }
        }
        ans = min(ans, tmpans);
    }
    cout << ans << endl;

    return 0;
}