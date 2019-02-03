#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    int h[101];
    cin >> N;
    for (int i; i < N; i++)
    {
        cin >> h[i];
    }
    int ans = 0;
    int t = 0;
    for (int i = 0; i < N; i++)
    {
        if (h[i] > t)
        {
            ans = ans + h[i] - t;
        }
        t = h[i];
    }
    cout << ans << endl;
    return 0;
}