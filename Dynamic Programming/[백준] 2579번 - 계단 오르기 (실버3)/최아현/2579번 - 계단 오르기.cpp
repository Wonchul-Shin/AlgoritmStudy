/*#include<iostream>
#include <algorithm>

using namespace std;

int stair[301] = { 0, }; // 계단
int dp[301] = { 0, }; 

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int  N, x;

	cin >> N;

	for (int i = 1; i <= N; i++) {

		cin >> stair[i];
	}
	for (int i = 1; i <= N; i++) {
		dp[i] = max(dp[i - 3] + stair[i - 1] + stair[i], dp[i - 2] + stair[i]); // 연속 3칸이 되지 않는 위치의 dp로 비교
	}
	cout << dp[N];
}*/