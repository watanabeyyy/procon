#include <iostream>
#include <vector>
#include <algorithm>
#include <ios>
#include <iomanip>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int P[100001], Y[100001];
    vector<int> list[100001];
    for (int i = 0; i < M; i++)
    {
        cin >> P[i] >> Y[i];
        list[P[i]].push_back(Y[i]);
    }
    for (int i = 0; i < N; i++) //Nにする。MにしてたためN>MのケースでWA連発した
    {
        sort(list[i + 1].begin(), list[i + 1].end());
    }
    int temp;
    for (int i = 0; i < M; i++)
    {
        cout << setfill('0') << right << setw(6) << P[i];
        // イテレータから添え字に変換する
        temp = int(lower_bound(list[P[i]].begin(), list[P[i]].end(), Y[i]) - list[P[i]].begin()) + 1;
        cout << setfill('0') << right << setw(6) << temp;
        cout << endl;
    }
    // cin >> N;
}