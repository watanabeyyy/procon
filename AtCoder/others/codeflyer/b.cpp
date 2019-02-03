#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    int A, B, N;
    cin >> A >> B >> N;
    string X;
    cin >> X;
    for (int i = 0; i < N; i++)
    {
        if (X[i] == 'S')
        {
            A--;
        }
        else if (X[i] == 'C')
        {
            B--;
        }
        else
        {
            if (A > B)
            {
                A--;
            }
            else if (A < B)
            {
                B--;
            }
            else
            {
                A--;
            }
        }
    }
    if (A < 0)
        A = 0;
    if (B < 0)
        B = 0;
    cout << A << endl;
    cout << B << endl;
    return 0;
}