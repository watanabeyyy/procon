#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(a) (a).begin(), (a).end()
typedef vector<int> vi;
const int INF = 1LL << 60;
const int MOD = 1000000007;
const int MAX_N = 200100;

signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    cout << "INF = " << INF << endl;
    cout << "-INF = " << -INF << endl;

    //正の割り算色々、難しいことはない
    cout << "1/2 = " << 1 / 2 << endl;
    cout << "1./2. = " << 1. / 2. << endl;
    cout << "1/2. = " << 1 / 2. << endl;
    cout << "1./2 = " << 1. / 2 << endl;
    cout << "floor(1./2) = " << floor(1. / 2) << endl;
    cout << endl;

    //負の床関数を扱いたいときはちょっと注意が必要。doubleにしてfloorを使うと楽。
    //負の場合については実はもっと安全な方法がある。後述。
    cout << "-1/2 = " << -1 / 2 << endl;
    cout << "floor(-1/2) = " << floor(-1 / 2) << endl;
    cout << "floor(-1/2.) = " << floor(-1 / 2.) << endl;
    cout << endl;

    //非常に大きな数の床関数を扱うときは不用意にdoubleを使うと情報落ちが発生してしまう。
    cout << "INF/3 = " << INF / 3 << endl;
    cout << "INF/3. = " << setprecision(20) << INF / 3. << endl;
    cout << "(int)(INF/3.) = " << (int)(INF / 3.) << endl;
    cout << "(int)floor(INF/3.) = " << (int)floor(INF / 3.) << endl;
    cout << endl;

    //正ならば楽だが、負の大きな値を扱うときにはどうすればいいか。
    //元の値を足した数を割ってから引けが所望の動作になる。
    cout << "(-1+1)/2-1 = " << (-1 + 1) / 2 - 1 << endl;
    cout << "(-INF+1)/3-1 = " << (-INF + 1) / 3 - 1 << endl;
    cout << endl;

    return 0;
}