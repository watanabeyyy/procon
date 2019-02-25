#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    string S;
    cin >> S;
    string ymd;
    ymd = S.substr(0, 4) + S.substr(5, 2) + S.substr(8, 2);
    int int_ymd;
    int_ymd = atoi(ymd.c_str());
    if (int_ymd <= 20190430)
    {
        cout << "Heisei";
    }
    else
    {
        cout << "TBD";
    }
    // system("pause");
}