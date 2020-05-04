#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(a) (a).begin(), (a).end()
typedef vector<int> vi;
const int INF = 1LL << 58;
const int MOD = 1000000007;
const int MAX_N = 200100;

int func(int b)
{
    return b * b * b * b * b;
}

// index が条件を満たすかどうか
bool isOK(int index, int key)
{
    if (func(index) >= key)
        return true;
    else
        return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(int key)
{
    //探索区間の初期値
    int left = -1000;
    int right = 1000;

    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while (right - left > 1)
    {
        int mid = left + (right - left) / 2;

        if (isOK(mid, key))
            right = mid;
        else
            left = mid;
    }

    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
    return right;
}

signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    int X;
    cin >> X;
    int a, b;
    b = -1000;
    while (1)
    {
        a = binary_search(X + func(b));
        if (func(a) - func(b) == X)
        {
            cout << a << " " << b;
            break;
        }
        b++;
    }

    return 0;
}