#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(void)
{
    int N;
    int p[110];
    set<int> st;

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> p[i];
    }
    st.insert(0);
    for (int i = 0; i < N; ++i)
    {
        set<int> temp;
        for (auto itr = st.begin(); itr != st.end(); ++itr)
        {
            temp.insert(*itr + p[i]);
        }
        for (auto itr = temp.begin(); itr != temp.end(); ++itr)
        {
            st.insert(*itr);
        }
    }
    cout << st.size() << endl;

    return 0;
}