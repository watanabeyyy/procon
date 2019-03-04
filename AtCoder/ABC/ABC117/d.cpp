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
    bitset<60> master;
    bitset<60> B;
    bitset<60> temp_bit;
    master = K;
    ll out = 0;
    int memo[60];
    for (int i = 0; i < 60; i++)
    {
        memo[i] = -1;
    }
    for (int idx = 59; idx >= 0; idx--)
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
                    temp_bit = A[i];
                    if (temp_bit[bit_cnt] == 1)
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
    ll X = K;
    ll temp = 0;
    for (int i = 0; i < N; i++)
    {
        temp += ll(A[i] ^ X);
    }
    chmax(out, temp);
    if (K == 0)
    {
        ll X = 0;
        ll temp = 0;
        for (int i = 0; i < N; i++)
        {
            temp += ll(A[i] ^ X);
        }
        out = temp;
    }
    cout << out;
    system("pause");
}