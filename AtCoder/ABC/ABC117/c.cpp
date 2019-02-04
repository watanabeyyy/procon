#include <iostream>
#include <vector>
#include <algorithm>
#include <ios>
#include <iomanip>

using namespace std;
typedef long long ll;

int main()
{
    int N, M;
    cin >> N >> M;
    if (N >= M)
    {
        cout << 0;
        return 0;
    }
    vector<int> X;
    int temp;
    for (int i = 0; i < M; i++)
    {
        cin >> temp;
        X.push_back(temp);
    }
    sort(X.begin(), X.end());
    vector<int> list;
    ll ans = 0;
    for (int i = 0; i < M - 1; i++)
    {
        list.push_back(X[i + 1] - X[i]);
        ans += X[i + 1] - X[i];
    }
    sort(list.begin(), list.end());
    for (int i = 0; i < N - 1; i++)
    {
        ans -= list[M - 2 - i];
    }
    cout << ans;
    // system("pause");
}