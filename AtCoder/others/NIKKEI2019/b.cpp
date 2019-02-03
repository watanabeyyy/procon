#include <iostream>

using namespace std;

int main()
{
    int N;
    char A[101];
    char B[101];
    char C[101];
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
    }
    int cnt;
    cnt = 0;
    for (int i = 0; i < N; i++)
    {
        int temp = 0;
        if (A[i] != B[i])
        {
            temp++;
        }
        else
        {
            temp--;
        }
        if (A[i] != C[i])
        {
            temp++;
        }
        else
        {
            temp--;
        }
        if (B[i] != C[i])
        {
            temp++;
        }
        else
        {
            temp--;
        }
        if (temp < 0)
        {
            temp = 0;
        }
        else if (temp > 2)
        {
            temp = 2;
        }
        cnt = cnt + temp;
    }
    cout << cnt << endl;
    return 0;
}