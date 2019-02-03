#include <iostream>
#include <vector>
#include <algorithm>
#include <ios>
#include <iomanip>

using namespace std;
typedef long long ll;

int main()
{
    int N;
    cin >> N;
    vector<ll> list;
    ll temp;
    ll sum = 0;
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        sum += temp;
        list.push_back(sum);
        if (sum == 0)
            ans++;
    }
    sort(list.begin(), list.end());
    ll len = 1;
    temp = list[0];
    for (int i = 1; i < N; i++)
    {
        if (temp != list[i])
        {
            ans += len * (len - 1) / 2;
            temp = list[i];
            len = 1;
        }
        else
        {
            len++;
        }
    }
    ans += len * (len - 1) / 2;
    cout << ans << endl;
    // system("pause");
}