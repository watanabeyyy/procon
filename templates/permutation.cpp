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

    int n;
    cin >> n;

    vector<int> one_case;
    for (int i = 0; i < n; i++)
    { // one_case = {0,1,2,3,...n-1} とする
        one_case.emplace_back(i);
    }

    do
    {
        for (auto num : one_case)
        {
            cout << num << " ";
        }
        cout << "\n";
    } while (next_permutation(one_case.begin(), one_case.end()));
    // 順列の最後になるまで one_case を並び替えながらループ

    return 0;
}