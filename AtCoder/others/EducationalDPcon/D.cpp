#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int N, W;
    cin >> N >> W;
    int w[100] = {};
    int v[100] = {};
    for (int i = 0; i<N;i++){
        cin >>w[i]>>v[i];
    }
    ll dp[2][100001] = {};
    dp[0][w[0]] = v[0];
    for (int i=1;i<N;i++){
        for(int j=0;j<W+1;j++){
            if(j >= w[i]){ 
                dp[1][j] = max(dp[0][j],dp[0][j-w[i]]+v[i]);
            }else{
                dp[1][j] = dp[0][j];
            }
        }
        for(int j=0;j<W+1;j++){
            dp[0][j] = dp[1][j];
        }
    }
    ll ans = 0;
    for (int j=0;j<W+1;j++){
        ans = max(ans, dp[0][j]);
    }
    cout << ans <<endl;

    // system("pause");
}