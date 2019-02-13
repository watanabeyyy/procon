#include <iostream>
#include <vector>
#include <algorithm>
#include <ios>
#include <iomanip>

using namespace std;
typedef long long ll;

int main()
{
    int N, K;
    cin >> N >> K;
    int maxnum;
    if (N%2 == 0){
        maxnum = N/2;
    }
    else{
        maxnum = (N+1)/2;
    }
    if ( maxnum >= K){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    // system("pause");
    return 0;
}