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
    int L[101];
    ll sum = 0;
    int M = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> L[i];
        sum += L[i];
        if (M < L[i])
        {
            M = L[i];
        }
    }
    if (M < (sum - M))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    // system("pause");
}