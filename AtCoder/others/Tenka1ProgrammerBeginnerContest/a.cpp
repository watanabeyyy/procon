#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string A;
    cin >> A;
    if (A.size() == 3)
    {
        reverse(A.begin(), A.end());
        cout << A;
    }
    else
    {
        cout << A;
    }
    return 0;
}