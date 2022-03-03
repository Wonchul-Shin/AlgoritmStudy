#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int num[1001] = { 0, };
int dp[1001] = { 0, };

int main() {

	int N, cnt = 0;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			if (num[j] < num[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
			if (cnt < dp[i]) {
				cnt = dp[i];
			}
		}
	}
	cout << cnt;

	return 0;
}

