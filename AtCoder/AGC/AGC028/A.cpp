#include <iostream>
#include <algorithm>
using namespace std;
// 最大公約数を求める関数
long gcd(int x, int y)
{
	long r;
	// ユーグリッドの互除法
	while ((r = x % y) != 0) // yで割り切れるまでループ
	{
		x = y;
		y = r;
	}
	return y;
}
long lcm(long x, long y)
{
	return (x * y / gcd(x, y));
}


int main(void) {
	long N, M;
	char S[100001];
	char T[100001];
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> T[i];
	}
	if (S[0] != T[0]) {
		cout << -1 << endl;
		return 0;
	}
	long L = lcm(N, M);
	long NN = L / N;
	long MM = L / M;
	long LL = lcm(NN, MM);
	for (long i = 1; i <= L/LL; i++) {
		if (i * LL /NN < N && i * LL / MM < M) {
			if (S[i*LL / NN] != T[i*LL / MM]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << L <<endl;
	return 0;
}