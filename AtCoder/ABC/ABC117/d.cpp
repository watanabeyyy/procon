#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
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

int main()
{
    int N;
    ll K;
    cin >> N >> K;
    ll A[100001];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    bitset<100> master;
    bitset<100> B;
    master = K;
    ll out = 0;
    int memo[100] = {-1};
    for (int idx = 99; idx >= 0; idx--)
    {
        if (master[idx] == 0)
        {
            continue;
        }
        B = master;
        B[idx] = 0;
        for (int bit_cnt = 0; bit_cnt < idx; bit_cnt++)
        {
            int cnt = 0;
            if (memo[bit_cnt] != -1)
            {
                cnt = memo[bit_cnt];
            }
            else
            {
                for (int i = 0; i < N; i++)
                {
                    if (A[i])
                    {
                        cnt++;
                    }
                }
                memo[bit_cnt] = cnt;
            }
            if (cnt > (N - cnt))
            {
                B[bit_cnt] = 0;
            }
            else
            {
                B[bit_cnt] = 1;
            }
        }
        ll X = ll(B.to_ullong());
        ll temp = 0;
        for (int i = 0; i < N; i++)
        {
            temp += ll(A[i] ^ X);
        }

        chmax(out, temp);
    }
    if (K == 0)
    {
        out = A[0];
    }
    cout << out;
    system("pause");
}