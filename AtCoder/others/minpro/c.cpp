#include <iostream>
#include <vector>
#include <algorithm>
#include <ios>
#include <iomanip>

using namespace std;
typedef long long ll;

int main()
{
    ll K,A,B;
    cin >> K >> A >> B;
    if ((B-A) <= 1){
        cout << 1 + K << endl;
        return 0;
    }
    ll bisk = 1;
    ll en = 0;
    for (int i=0;i<K;i++){
        if (en>0 && i<K-1){
            bisk = bisk + en * B;
            en--;
            K++;
        }
        else if (bisk >= A && i<K-1){
            bisk = bisk - A;
            en++;
            K--;
        }
        else{
            bisk++;
        }
    }
    ll ans;
    ans = bisk + en*B;
    cout << ans << endl;
    // system("pause");
}