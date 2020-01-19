#include <bits/stdc++.h>
using namespace std;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b)
{
   if (b == 0)
      return a;
   else
      return GCD(b, a % b);
}

/* a と b の最小公倍数を求める */
long long LCM(long long a, long long b)
{
   long long g = GCD(a, b);
   return a / g * b;
}

int main()
{
   int a, b;
   a = 10;
   b = 16;

   // 最大公約数
   cout << GCD(a, b) << endl;
   //最小公倍数
   cout << LCM(a, b) << endl;
   return 0;
}
