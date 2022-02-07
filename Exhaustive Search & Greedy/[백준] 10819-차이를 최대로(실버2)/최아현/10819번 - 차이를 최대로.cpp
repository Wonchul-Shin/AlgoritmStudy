#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, x, max = 0;
	cin >> N;
	vector<int> A(N);

	for (int i = 0; i < N; i++) {
		cin >> x;
		A[i] = x;
 	}
	sort(A.begin(),A.end());

	do {  
		int total = 0;

		for (int i = 0; i < N - 1; i++) {
			total += abs(A[i] - A[i + 1]); // 계산
		}
		//printf("%d\n", total);

		if (max < total) { // 큰 값 비교
			max = total;
		}

	} while (next_permutation(A.begin(), A.end())); //수열 함수

	cout << max;

	return 0;
}