#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int N, W;
    cin >> N >> W;
    ll w[100] = {};
    int v[100] = {};
    for (int i = 0; i<N;i++){
        cin >>w[i]>>v[i];
    }
    ll dp[2][100001];
    for(int i=0;i<2;i++){
        for (int j=0;j<100001;j++){
            dp[i][j] = 1e10;
        }
    }

    dp[0][0] = 0;
    dp[0][v[0]] = w[0];
    for (int i=1;i<N;i++){
        for(int j=0;j<100001;j++){
            if(j >= v[i]){ 
                dp[1][j] = min(dp[0][j],dp[0][j-v[i]]+w[i]);
            }else{
                dp[1][j] = dp[0][j];
            }
        }
        for(int j=0;j<100001;j++){
            dp[0][j] = dp[1][j];
        }
    }
    ll ans = 0;
    for (int j=100000;j>=0;j--){
        if (dp[0][j]<=W){
            ans = j;
            break;
        }
    }
    cout << ans << endl;

    // system("pause");
}