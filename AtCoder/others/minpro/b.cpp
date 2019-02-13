#include <iostream>
#include <vector>
#include <algorithm>
#include <ios>
#include <iomanip>

using namespace std;
typedef long long ll;

int main()
{
    int A[3][2];
    int count[4];
    for (int i=0;i<4;i++){
        count[i]=0;
    }
    for (int i=0;i<3;i++){
        cin >> A[i][0] >> A[i][1];
        count[A[i][0]-1]++;
        count[A[i][1]-1]++;
    }
    int cnt=0;
    for (int i=0;i<4;i++){
        if(count[i] == 1){
            cnt++;
        }
    }
    if (cnt == 2){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    // system("pause");
}