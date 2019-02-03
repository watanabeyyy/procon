#include <iostream>

using namespace std;
int ans = 0;
int N;
void dfs(long long x, int a, int b, int c)
{
    if (x > N)
    {
        return;
    }
    if (a && b && c)
    {
        ans++;
    }
    dfs(x * 10 + 7, a + 1, b, c);
    dfs(x * 10 + 5, a, b + 1, c);
    dfs(x * 10 + 3, a, b, c + 1);
}

int main(void)
{
    cin >> N;
    dfs(0, 0, 0, 0);
    cout << ans << endl;
    return 0;
}
