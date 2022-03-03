#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {

	string a, b;
	int dp[1001][1001] = { 0, };

	cin >> a >> b;

	int a_size = a.length();
	int b_size = b.length();

	for (int i = 1; i <= a_size; i++)
	{
		for (int j = 1; j <= b_size; j++) // 최대공통부분문자열
		{
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[a_size][b_size];

	return 0;
}