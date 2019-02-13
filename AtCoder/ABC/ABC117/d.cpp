#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//まだWA
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
    bitset<100> B;
    bitset<100> ans;
    for (int bit_cnt = 0; bit_cnt < 100; bit_cnt++)
    {
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            if (A[i] & (1 << bit_cnt))
            {
                cnt++;
            }
        }
        if (cnt >= N - cnt)
        {
            B &= ~(1 << bit_cnt);
        }
        else
        {
            B |= (1 << bit_cnt);
        }
        if (B.to_ullong() <= K)
        {
            ans = B;
        }
    }
    ll X = ll(ans.to_ullong());
    ll out = 0;
    for (int i = 0; i < N; i++)
    {
        out += ll(A[i] ^ X);
    }

    cout << out;
    // system("pause");
}