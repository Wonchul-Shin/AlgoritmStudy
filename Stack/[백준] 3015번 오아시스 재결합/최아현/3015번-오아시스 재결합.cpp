#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N;
	int in;
	vector<int> v;

	int point = 0;
	int result = 0;
	int sw = 0;
	int count = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> in;
		v.insert(v.begin() + i, in);
	}

	while (point < N) {

		for (int i = point + 2; i < N; i++) {
			count = 0;
			for (int j = point + 1; j < i; j++) {
				if (v[point] < v[j] && v[i] < v[j]) {
					break;
				}
				else if (v[point] == v[j] && v[i] < v[j]) {
					break;
				}
				else if (v[point] < v[j] && v[i] == v[j]) {
					break;
				}
				if (j == i - 1){
					count++;
				}
			}
			result += count;
		}
		point++;
	}

	cout << result + (N-1);

	return 0;
}
