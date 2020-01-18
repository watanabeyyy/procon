#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;

// 負の数にも対応した % 演算
long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) res += m;
    return res;
}

// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}


signed main()
{
    long long a,b,c;
    
    //a-b
    //負の割り算なら関数modを使う
    a = 2000000020;
    b = 20;
    cout <<  (a - b) % MOD << endl;//"普通に計算して余りを求める: "
    cout << ((a%MOD) - (b%MOD)) % MOD << endl;//"余り求めてから計算して余りを求める: "
    cout << mod((a%MOD) - (b%MOD), MOD) << endl;//"余り求めてから計算して余りを求める (対策済): "

    //a*b*c
    a = 111111111;
    b = 123456789;
    c = 987654321;
    cout << a * b * c % MOD << endl;       // a*b*c がオーバーフローするので間違った答えに
    cout << a * b % MOD * c % MOD << endl; // a*b で一旦 MOD をとる

    //a/b
    a = 12345678900000;
    b = 100000;
    // a を 10000000007 で割ってから b の逆元をかけて計算
    a %= MOD;
    cout << a * modinv(b, MOD) % MOD << endl;
    
    return 0;
}