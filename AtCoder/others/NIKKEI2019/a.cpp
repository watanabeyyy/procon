#include <iostream>

using namespace std;

int main()
{
    int A, B, N;
    cin >> N >> A >> B;
    int out;
    if (A + B - N < 0)
    {
        out = 0;
    }
    else
    {
        out = A + B - N;
    }
    cout << min(A, B) << " " << out << endl;
    return 0;
}