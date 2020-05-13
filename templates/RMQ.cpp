#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(a) (a).begin(), (a).end()
typedef vector<int> vi;
const int INF = 1LL << 58;
const int MOD = 998244353;
const int MAX_N = 200100;

/* RMQ：[0,n-1] について、区間ごとの最小値を管理する構造体
    update(a,b,x): 区間[a,b) の要素を x に更新。O(log(n))
    query(a,b): [a,b) での最小の要素を取得。O(log(n))
*/
template <typename T>
struct RMQ
{
    const T INF = numeric_limits<T>::max();
    int n;
    vector<T> dat, lazy;
    RMQ(int n_) : n(), dat(n_ * 4, INF), lazy(n_ * 4, INF)
    {
        int x = 1;
        while (n_ > x)
            x *= 2;
        n = x;
    }

    /* lazy eval */
    void eval(int k)
    {
        if (lazy[k] == INF)
            return; // 更新するものが無ければ終了
        if (k < n - 1)
        { // 葉でなければ子に伝搬
            lazy[k * 2 + 1] = lazy[k];
            lazy[k * 2 + 2] = lazy[k];
        }
        // 自身を更新
        dat[k] = lazy[k];
        lazy[k] = INF;
    }

    void update(int a, int b, T x, int k, int l, int r)
    {
        eval(k);
        if (a <= l && r <= b)
        { // 完全に内側の時
            lazy[k] = x;
            eval(k);
        }
        else if (a < r && l < b)
        {                                               // 一部区間が被る時
            update(a, b, x, k * 2 + 1, l, (l + r) / 2); // 左の子
            update(a, b, x, k * 2 + 2, (l + r) / 2, r); // 右の子
            dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    void update(int a, int b, T x) { update(a, b, x, 0, 0, n); }

    T query_sub(int a, int b, int k, int l, int r)
    {
        eval(k);
        if (r <= a || b <= l)
        { // 完全に外側の時
            return INF;
        }
        else if (a <= l && r <= b)
        { // 完全に内側の時
            return dat[k];
        }
        else
        { // 一部区間が被る時
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }

    /* debug */
    inline T operator[](int a) { return query(a, a + 1); }
    void print()
    {
        for (int i = 0; i < 2 * n - 1; ++i)
        {
            cout << (*this)[i];
            if (i != n)
                cout << ",";
        }
        cout << endl;
    }
};

int ruiseki[MAX_N];
signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    int N;
    cin >> N;
    vector<int> v;
    map<int, int> mp;
    REP(i, N)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(a);
        mp[a] = b;
    }
    v.push_back(INF);
    sort(ALL(v));

    //セグメント木でiを触ったときに最終的にどのロボットまで動作してしまうかを管理する
    RMQ<int> rmq(N);
    REP(i, N)
    {
        int t = v[i];
        int d = distance(v.begin(), lower_bound(v.begin(), v.end(), t + mp[t] - 1));
        if (v[d] == t + mp[t] - 1) //ピッタリ
        {
            d = d;
        }
        else //一個前まで
        {
            d = d - 1;
        }
        rmq.update(i, i + 1, -d);
    }

    ruiseki[N] = 0;
    REP(i, N)
    {
        int d = rmq.query(N - 1 - i, N - i);
        if (-d != N - 1 - i)
        {
            d = rmq.query(N - 1 - i, -d + 1);
        }
        rmq.update(N - 1 - i, N - i, d);

        ruiseki[N - 1 - i] = (1 + ruiseki[-d + 1]) + ruiseki[N - i];
        ruiseki[N - 1 - i] %= MOD;
    }
    cout << ruiseki[0] + 1 << endl;

    return 0;
}
