#include <bits/stdc++.h>
using namespace std;

// 最大公約数
int gcd(int a, int b)
{
   if (a%b == 0)
       return(b);
   else
       return(gcd(b, a%b));
}

//最小公倍数
int lcm(int a, int b)
{
   return a * b / gcd(a, b);
}

int main()
{
   int a, b;
   a = 10;
   b = 16;

   // 最大公約数
   cout << gcd(a, b) << endl;
   //最小公倍数
   cout << lcm(a, b) << endl;
   return 0;
}
