#include <iostream>
using namespace std;
int main(void)
{
    int A, B;
    cin >> A >> B;
    int ans;
    ans = int(A / B) * B;
    cout << ans << endl;
    return 0;
}